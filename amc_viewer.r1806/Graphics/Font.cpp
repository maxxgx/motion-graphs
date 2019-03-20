#include "Font.hpp"
#include "Graphics.hpp"
extern "C" {
#include "texfont.h"
}

#include <iostream>

using std::cerr;
using std::endl;

namespace Graphics {

CachedFont::CachedFont(TexFont *_font) : font(_font) {
	id = FONT_ID;
	int width, ascent, descent;
	txfGetStringMetrics(font, "ABCDEFGHIGHLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwyxz", 52, &width, &ascent, &descent);
	scale_factor = 1.0f / (float)(ascent + descent);
	translation_factor = (float)descent;
	reload();
}

CachedFont::~CachedFont() {
	txfUnloadFont( font );
	font = NULL;
}

void CachedFont::reload() {
	txfEstablishTexture(font, font->texobj, GL_TRUE);
	txfBindFontTexture(font);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

float CachedFont::get_length(string const &text, float height) const {
	int width, ascent, descent;
	txfGetStringMetrics(font, (char *)text.c_str(), text.size(), &width, &ascent, &descent);
	return(width * scale_factor * height);
}

void CachedFont::draw(string const &text, Vector2f const &pos, float height) const {
	glPushMatrix();
	glTranslated(pos.x, pos.y, 0);
	glScaled(scale_factor * height, scale_factor * height, 1);
	glTranslated(0, translation_factor, 0);
	glEnable(GL_TEXTURE_2D);
	txfBindFontTexture(font);
	txfRenderString(font, (char *)text.c_str(), text.size());
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

CacheRef< CachedFont > get_font(string name) {
	string key = "font:" + name;
	CacheRef< CachedFont > ret(NULL);
	CachedFont *item = (CachedFont *)get_cache().get_item(key);
	if (!item) {
		TexFont *font = txfLoadFont(name.c_str());
		if (font == NULL) {
			cerr << "Error loading font '" << name << "'." << endl;
			return ret;
		}
		item = new CachedFont(font);
		get_cache().add_item(key, item);
	}
	if (item->id != FONT_ID) {
		cerr << "Item with key '" << key << "' isn't a font." << endl;
		return ret;
	}
	ret.set(item);
	return ret;
}

} //namespace Graphics
