#ifndef GRAPHICS_FONT
#define GRAPHICS_FONT

#include <Vector/Vector.hpp>
#include "Cache.hpp"
#include <string>
#include "Graphics.hpp"
extern "C" {
#include "texfont.h"
}

namespace Graphics {

using std::string;

const unsigned int FONT_ID = 0xcaf3caf3;

class CachedFont : public CachableItem {
public:
	CachedFont(TexFont *font);
	virtual ~CachedFont();
	virtual void reload();
	float get_length(string const &text, float height) const;
	void draw(string const &text, Vector2f const & pos, float height) const;
	TexFont *font;
	float scale_factor;
	float translation_factor;
};

typedef CacheRef< CachedFont > FontRef;

FontRef get_font(string fontname = "default.txf");

} //namespace Graphics

#endif //GRAPHICS_FONT
