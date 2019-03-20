#ifndef GRAPHICS_GLSLSHADER_HPP
#define GRAPHICS_GLSLSHADER_HPP

#include "GLExtensions.hpp"

#include "Cache.hpp"

#include <string>
#include <vector>

namespace Graphics {

using std::string;
using std::vector;

const unsigned int SHADEROBJECT_ID = 0xfeedf00d;
const unsigned int PROGRAMOBJECT_ID = 0x00c0ffee;

class CachedShaderObject : public CachableItem {
public:
	CachedShaderObject(vector< string > const &source, GLenum const type);
	virtual ~CachedShaderObject();
	virtual void reload();
	vector< string > source;
	GLenum type;
	GLhandleARB handle;
};

typedef CacheRef< CachedShaderObject > ShaderObjectRef;

//One of these is the function you (Mme. User) need to call:
ShaderObjectRef get_shader_object(string const &filename, GLenum const type);
//This version is for dynamically inserting definitions and such:
ShaderObjectRef get_shader_object(vector< string > const &insert, string const &filename, GLenum const type);
//This version for entirely dynamically generated shaders:
ShaderObjectRef get_shader_object_from_text(string const &text, GLenum const type);

class CachedProgramObject : public CachableItem {
public:
	CachedProgramObject(vector< ShaderObjectRef > &objects);
	virtual ~CachedProgramObject();
	virtual void reload();
	vector< ShaderObjectRef > &objects;
	GLhandleARB handle;
};

typedef CacheRef< CachedProgramObject > ProgramObjectRef;

//This is the other function that you users need:
ProgramObjectRef get_program_object(vector< ShaderObjectRef > &objects);
ProgramObjectRef get_program_object(ShaderObjectRef &object);


} //namespace Graphics

#endif //GRAPHICS_GLSLSHADER_HPP
