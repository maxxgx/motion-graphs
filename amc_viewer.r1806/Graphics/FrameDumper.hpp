#ifndef GRAPHICS_FRAMEDUMPER_HPP
#define GRAPHICS_FRAMEDUMPER_HPP

#include <string>

namespace Graphics {

/*
 * This is a threaded frame-dumper, which I hope will be fast enough
 * to use for video recording without degrading performance.
 *
 * Behind the scenes, this is using threads and SDL timers to figure out
 * what is dump-worthy, and to queue it for disk writes.
 */


//filename is a pattern of the for file0000.ppm, where those zeros will
//get the frame number.
// -- fps == 0 is a special case where every frame is dumped. --
void init_dumper(std::string const &basename, float fps);
bool dumper_active();
void deinit_dumper();

//Call this after a frame is finished and before you flip it to
//the front buffer [i.e. it should still be on the back buffer].
void submit_frame();

}

#endif //GRAPHICS_FRAMEDUMPER_HPP
