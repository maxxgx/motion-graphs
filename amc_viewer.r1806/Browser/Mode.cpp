#include "Mode.hpp"

Mode::Mode() :
		min_ms_per_frame(1000/100),
		max_ms_per_frame(1000/15),
		quit_flag(false) {
}

Mode::~Mode() {
}

void Mode::main_loop() {
	Uint32 env_t = SDL_GetTicks();
	Uint32 env_et = 0;
	SDL_Event event;
	while (!quit_flag) {
		//Find elapsed milliseconds, delaying and clamping as needed.
		env_et = SDL_GetTicks() - env_t;
		while (env_et < min_ms_per_frame) {
			SDL_Delay(min_ms_per_frame - env_et);
			env_et = SDL_GetTicks() - env_t;
		}
		env_t += env_et;
		if (env_et > max_ms_per_frame) env_et = max_ms_per_frame;

		//get and process any new events.
		while (SDL_PollEvent(&event)) {
			handle_event(event);
			//add alt-escape as a sort of force-quit:
			if (event.type == SDL_KEYDOWN
				&& event.key.keysym.sym == SDLK_ESCAPE
				&& (event.key.keysym.mod & KMOD_ALT) ) {
				quit_flag = true;
			}
		}
		
		//update the world
		update(env_et / 1000.0f);
		
		//draw the world
		draw();

		//swap the drawn world to the front buffer
		SDL_GL_SwapBuffers();
	}
}

void Mode::update(float const elapsed_time) {
	//empty
}

void Mode::handle_event(SDL_Event const &event) {
	//empty
}

void Mode::draw() {
	//empty
}
