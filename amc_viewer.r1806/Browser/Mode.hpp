#ifndef MODE_HPP
#define MODE_HPP

#include <SDL.h>

/*
 * This is the generic 'mode' class which encompases a current game state.
 * It contains a 'main_loop()' call which kicks it off.
 * the tick, handle_event, and draw calls are invoked by the main_loop.
 */

class Mode {
public:
	Mode();
	virtual ~Mode();

	//calls handle_event, tick, and draw at appropriate times.
	virtual void main_loop();
	
	//update the current world
	virtual void update(float const elapsed_time);
	
	//handle the given sdl input event
	virtual void handle_event(SDL_Event const &event);
	
	//draw the current game world.
	virtual void draw();
	
	//if a frame took less than this amount of time to render, wait.
	// (This prevents the cpu from being hogged.)
	Uint32 min_ms_per_frame;
	
	//if a frame took more than this amount of time to render, pretend it
	//didn't (results in a game slow-down)
	Uint32 max_ms_per_frame;

	//Indicates that the mode should be quit.
	bool quit_flag;
};

#endif //GAME_MODE_HPP
