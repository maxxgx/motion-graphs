#include "Graphics.hpp"

#include <iostream>
#include <list>
#include <utility>
#include <assert.h>

using std::cerr;
using std::endl;

using std::list;
using std::pair;
using std::make_pair;

namespace Graphics {

int screen_x = 800;
int screen_y = 600;
bool fullscreen = false;

namespace { //private-type variables.
SDL_Surface *surface = NULL;
bool sub_inited = false;
bool inited = false;

list< pair< void (*)(void *), void * > > & get_init_funcs() {
	static list< pair< void (*)(void *), void * > > init_funcs;
	return init_funcs;
}
} //end anon namespace

bool init(int flags) {
	
	if (SDL_InitSubSystem(SDL_INIT_VIDEO) == 0) {
		sub_inited = true;
		
		SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8);
		SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8);
		SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8);
		if (flags & NEED_ACCUM) {
			SDL_GL_SetAttribute( SDL_GL_ACCUM_RED_SIZE, 16);
			SDL_GL_SetAttribute( SDL_GL_ACCUM_GREEN_SIZE, 16);
			SDL_GL_SetAttribute( SDL_GL_ACCUM_BLUE_SIZE, 16);
		}
		//SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8);
		//SDL_GL_SetAttribute( SDL_GL_BUFFER_SIZE, 32);
		SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 24);
		if (flags & NEED_STENCIL) {
			SDL_GL_SetAttribute( SDL_GL_STENCIL_SIZE, 8);
		}
		SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1);
		if (flags & NEED_VSYNC) {
			#ifdef SDL_GL_SWAP_CONTROL
			SDL_GL_SetAttribute( SDL_GL_SWAP_CONTROL, 1);
			#else
			cerr << "Using a version of SDL that doesn't support VSYNC." << endl;
			#endif
		}

		if (fullscreen) {
			surface = SDL_SetVideoMode(screen_x, screen_y, 24, SDL_OPENGL | SDL_FULLSCREEN);
		} else {
			surface = SDL_SetVideoMode(screen_x, screen_y, 24, SDL_OPENGL);
		}

		if (surface) {
			inited = true;
		} else {
			cerr << "Could not create video surface: " << SDL_GetError() << endl;
		}
	} else {
		cerr << "Could not init video: " << SDL_GetError() << endl;
	}

	if (sub_inited && !inited) {
		deinit();
	}

	if (inited) {
		while (!get_init_funcs().empty()) {
			get_init_funcs().back().first(get_init_funcs().back().second);
			get_init_funcs().pop_back();
		}
	}
	
	return inited;

}

void deinit() {
	if (sub_inited) {
		SDL_QuitSubSystem(SDL_INIT_VIDEO);
		sub_inited = false;
		inited = false;
		surface = NULL;
	}
}

bool initialized() {
	return inited;
}

void on_init(void (*func)(void *), void *data) {
	assert(!initialized()); //only to be called before init.
	get_init_funcs().push_back(make_pair(func, data));
}

void gl_errors(string const &where) {
	GLuint err;
	while ((err = glGetError()) != GL_NO_ERROR) {
	cerr << "(in " << where << ") OpenGL error #" << err
	     << ": " << gluErrorString(err) << endl;
	}
}

}
