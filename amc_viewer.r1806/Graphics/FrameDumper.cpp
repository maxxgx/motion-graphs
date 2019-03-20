#include "FrameDumper.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <poll.h>

#include <Graphics/Graphics.hpp>
#include <SDL.h>
#include <SDL_thread.h>

#include <cstdlib>
#include <sstream>
#include <iostream>
#include <assert.h>

using std::string;
using std::ostringstream;
using std::cerr;
using std::endl;

namespace Graphics {

namespace {

bool inited = false;

//used by the dumper thread:
unsigned int frame_number = 0;
bool quit_thread = false;

const unsigned int MaxName = 234;
char namebuffer[MaxName];
unsigned int num_first = 0;
unsigned int num_last = 0;

const unsigned int MaxHeader = 1000;
char file_header[MaxHeader];
unsigned int file_header_len = 0;

//used by the submit thread:
float seconds_per_frame = 1.0f;
float elapsed_time = 0.0f;
bool first_frame = true;

//used by everyone:
SDL_sem *buffer_free = NULL; //there is a buffer ready to be filled
SDL_sem *buffer_full = NULL; //there is a buffer ready to be dumped
//Invariant: buffer_free + buffer_full == BufferCount.

const unsigned int BufferCount = 100;
char *buffers[BufferCount];
unsigned int buffer_reps[BufferCount];
unsigned int buffer_head = 0;
unsigned int buffer_tail = 0;

SDL_Thread *dump_thread;

void write_loop(int fd, char *buffer, unsigned int len) {
	unsigned int written = 0;
	unsigned int errors = 0;
	while (written < len) {
		unsigned int amt = 1024*4;
		if (len - written < amt) amt = len - written;
		{
			struct pollfd p;
			p.fd = fd;
			p.events = POLLOUT;
			p.revents = 0;
			poll(&p, 1, -1); //wait forever for fd to be writable.
		}
		unsigned int ret = write(fd, buffer + written, amt);
		if (ret < 0) {
			cerr << "ERROR writing data." << endl;
			++errors;
			assert(errors < 10);
		} else {
			written += ret;
		}
	}
}

void dump_buffer() {
	unsigned int temp = frame_number;
	++frame_number;
	for (unsigned int x = num_last; x + 1 != num_first; --x) {
		namebuffer[x] = ('0' + (temp % 10));
		temp /= 10;
	}
	int fd = open(namebuffer, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd < 0) {
		cerr << "ERROR opening '" << namebuffer << "'" << endl;
		assert(0);
	}
	write_loop(fd, file_header, file_header_len);
	write_loop(fd, buffers[buffer_tail], Graphics::screen_x * Graphics::screen_y * 3);
	close(fd);
	buffer_tail = (buffer_tail + 1) % BufferCount;
}

int dump_thread_main(void *) {
	while (1) {
		SDL_SemWait(buffer_full);
		if (quit_thread) return 0;
		dump_buffer();
		SDL_SemPost(buffer_free);
	}
	return 0;
}

}

void init_dumper(std::string const &filename, float _fps) {
	assert(inited == false);
	if (_fps == 0.0f) {
		seconds_per_frame = 0.0f;
	} else {
		seconds_per_frame = 1.0f / _fps;
	}
	elapsed_time = 0.0f;
	first_frame = true;

	frame_number = 0;
	quit_thread = false;

	buffer_head = buffer_tail = 0;

	//Set up the filename buffer:
	assert(filename.size() + 1 < MaxName);
	strncpy(namebuffer, filename.c_str(), MaxName);
	num_last = filename.size() - 1;
	while (num_last < filename.size() && filename[num_last] != '0') {
		--num_last;
	}
	num_first = num_last;
	while (num_first < filename.size() && filename[num_first] == '0') {
		--num_first;
	}
	++num_first;
	assert(num_last < filename.size() && num_first < filename.size());

	//Set up the file header:
	ostringstream file_header_stream;
	file_header_stream << "P6\n" << Graphics::screen_x << " " << Graphics::screen_y << '\n' << "255\n";
	assert(file_header_stream.str().size() + 1 < MaxHeader);
	strncpy(file_header, file_header_stream.str().c_str(), MaxHeader);
	file_header_len = file_header_stream.str().size();


	//Set up the buffers:
	for (unsigned int i = 0; i < BufferCount; ++i) {
		buffers[i] = new char[Graphics::screen_x * Graphics::screen_y * 3];
		buffer_reps[i] = 0;
	}

	//Create the semaphores:
	if (!buffer_free) {
		buffer_free = SDL_CreateSemaphore(BufferCount-1);
	}
	if (!buffer_full) {
		buffer_full = SDL_CreateSemaphore(0);
	}

	//Set up the semaphores:
	while (SDL_SemValue(buffer_free) < BufferCount - 1) {
		SDL_SemPost(buffer_free);
	}
	while (SDL_SemValue(buffer_full) > 0) {
		SDL_SemWait(buffer_full);
	}

	//Create the dump thread:
	dump_thread = SDL_CreateThread(dump_thread_main, NULL);

	inited = true;
}

bool dumper_active() {
	return inited;
}

void deinit_dumper() {
	assert(inited);

	quit_thread = true;
	SDL_SemPost(buffer_full); //make sure it gets the the quitting code.
	SDL_WaitThread(dump_thread, NULL);

	dump_thread = NULL;

	SDL_DestroySemaphore(buffer_full);
	SDL_DestroySemaphore(buffer_free);

	buffer_full = buffer_free = NULL;

	//clean up lingering frames:
	while (buffer_tail != buffer_head) {
		dump_buffer();
	}

	//deallocate buffer storage:
	for (unsigned int i = 0; i < BufferCount; ++i) {
		delete[] buffers[i];
		buffers[i] = NULL;
	}

	inited = false;
}


void submit_frame() {
	if (!dumper_active()) {
		cerr << "Please call submit frame only when the dumper is active." << endl;
		return;
	}
	if (seconds_per_frame != 0.0f) {
		static Uint32 last_ticks = 0;
		if (first_frame) {
			last_ticks = SDL_GetTicks();
			first_frame = false;
		} else {
			Uint32 ticks = SDL_GetTicks();
			elapsed_time += (ticks - last_ticks) / 1000.0f;
			last_ticks = ticks;
			while (elapsed_time > 0.0f) {
				elapsed_time -= seconds_per_frame;
				buffer_reps[buffer_head] += 1;
			}
			if (buffer_reps[buffer_head]) {
				if (SDL_SemValue(buffer_free) == 0) {
					cerr << "Starving for buffers in the frame dumper." << endl;
				}
				SDL_SemWait(buffer_free);
				buffer_head = (buffer_head + 1) % BufferCount;
				buffer_reps[buffer_head] = 0;
				SDL_SemPost(buffer_full);
			}
		}
	}
	//read the frame:
	glReadPixels(0,0,Graphics::screen_x,Graphics::screen_y, GL_RGB, GL_UNSIGNED_BYTE, buffers[buffer_head]);
	if (seconds_per_frame == 0.0f) {
		buffer_reps[buffer_head] = 1;
		if (SDL_SemValue(buffer_free) == 0) {
			cerr << "Starving for buffers in the frame dumper." << endl;
		}
		SDL_SemWait(buffer_free);
		buffer_head = (buffer_head + 1) % BufferCount;
		buffer_reps[buffer_head] = 0;
		SDL_SemPost(buffer_full);
	}
}

}
