#ifndef GRAPHICS_TEXTURE_HPP
#define GRAPHICS_TEXTURE_HPP

#include "Graphics.hpp"

#include "Cache.hpp"

#include <string>
#include <vector>

namespace Graphics {

using std::string;
using std::vector;

const unsigned int TEXTURE_ID = 0xabadbad1;

class CachedTexture : public CachableItem {
public:
	CachedTexture(string const &filename, bool pad);
	virtual ~CachedTexture();
	virtual void reload();
	string filename;
	bool pad;
	GLuint obj;
	unsigned int w,h;
	unsigned int tw, th; //if pad == true, then texture has been padded to a power of two and is really tw x th.
};

typedef CacheRef< CachedTexture > TextureRef;

//One of these is the function you (Mme. User) need to call:
TextureRef get_texture(string const &filename, bool pad = false);

} //namespace Graphics

#endif //GRAPHICS_TEXTURE_HPP
