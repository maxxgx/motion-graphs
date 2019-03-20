
#include "BrowseMode.hpp"

#include <Library/Library.hpp>

#include <Graphics/Graphics.hpp>

#include <SDL.h>
#include <SDL_opengl.h>

#include <iostream>
#include <fstream>

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;

int main(int argc, char **argv) {

	string path = "data";
	if (argc == 2) {
		path = argv[1];
	}
	Library::init(path);

	if (Library::motion_count() == 0) {
		cerr << "------------ERROR-------------" << endl;
		cerr << "Could not find any motions to browse in directory '" << path << "'.\nPlease either place amc files and associated asf here, or specify a different\n directory on on the command line." << endl;
		return 1;
	}

	if (SDL_Init(SDL_INIT_TIMER) != 0) {
		cerr << "------------ERROR-------------" << endl;
		cout << "Could not initialize sdl: " << SDL_GetError() << endl;
		return 1;
	}

	if (!Graphics::init(Graphics::NEED_STENCIL)) {
		cerr << "------------ERROR-------------" << endl;
		cout << "Could not initialize graphics, not continuing." << endl;
		exit(1);
	}

	BrowseMode mode;
	
	mode.main_loop();

	Graphics::deinit();

	SDL_Quit();

	return 0;
}
