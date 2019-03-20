#include "GLSLShader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using std::ifstream;
using std::ostringstream;

using std::cerr;
using std::endl;

//Is this a complete list? I'm not sure...
REQUIRE_GL_EXTENSION(GL_ARB_shading_language_100);
REQUIRE_GL_EXTENSION(GL_ARB_shader_objects);
REQUIRE_GL_EXTENSION(GL_ARB_fragment_shader);
REQUIRE_GL_EXTENSION(GL_ARB_vertex_shader);

namespace Graphics {

namespace {
	string shader_log(GLhandleARB shader) {
		GLint len = 0;
		glGetObjectParameterivARB(shader, GL_OBJECT_INFO_LOG_LENGTH_ARB, &len);
		vector< GLchar > log(len, '\0');
		GLint written = 0;
		glGetInfoLogARB(shader, len, &written, &log[0]);
		assert(written <= len);
		string out = "";
		for (unsigned int i = 0; i < log.size() && log[i] != '\0'; ++i) {
			out += log[i];
		}
		return out;
	}
}

CachedShaderObject::CachedShaderObject(vector< string > const &_source, GLenum const _type) : source(_source), type(_type), handle(0) {
	id = SHADEROBJECT_ID;
	loaded = false;
	reload();
}

CachedShaderObject::~CachedShaderObject() {
	if (loaded) {
		if (handle != 0) {
			glDeleteObjectARB(handle);
			Graphics::gl_errors("~CachedShaderObject()");
		}
	}
}

void CachedShaderObject::reload() {
	handle = glCreateShaderObjectARB(type);
	vector< const GLchar * > strings(source.size(), 0);
	vector< GLint > lengths(source.size(), 0);
	for (unsigned int i = 0; i < source.size(); ++i) {
		strings[i] = (const GLchar *)source[i].c_str();
		lengths[i] = source[i].size();
	}
	glShaderSourceARB(handle, strings.size(), &(strings[0]), &(lengths[0]));
	Graphics::gl_errors("CachedShaderObject::reload @ ShaderSourceARB");
	glCompileShaderARB(handle);
	Graphics::gl_errors("CachedShaderObject::reload @ CompileShaderARB");
	GLint val = 0;
	glGetObjectParameterivARB(handle, GL_OBJECT_COMPILE_STATUS_ARB, &val);
	string log = shader_log(handle);
	if (val == 0) {
		cerr << "CachedShaderObject::reload: Problem compiling shader." << endl;
		cerr << "Log:" << endl << log;
		return;
	}
	if (log != "") {
		cerr << "Warnings while compiling shader:" << endl;
		cerr << "Log:" << endl << log;
	}
	loaded = true;
	Graphics::gl_errors("CachedShaderObject::reload");
}

ShaderObjectRef get_shader_object(string const &filename, GLenum const type) {
	vector< string > empty;
	empty.clear();
	return get_shader_object(empty, filename, type);
}


ShaderObjectRef get_shader_object(vector< string > const &ins, string const &filename, GLenum const type) {
	ostringstream key;
	key << "shader:" << type;
	for (unsigned int i = 0; i < ins.size(); ++i) {
		key << "+" << ins[i];
	}
	key << "/" << filename;
	CacheRef< CachedShaderObject > ret(NULL);
	CachedShaderObject *item = (CachedShaderObject *)get_cache().get_item(key.str());
	if (!item) {

		ifstream file(filename.c_str());
	
		if (filename != "" && !file.is_open()) {
			cerr << "Can't open file '" << filename << "' while loading shader." << endl;
			return ret;
		}

		vector< string > lines;
		for (unsigned int i = 0; i < ins.size(); ++i) {
			lines.push_back(ins[i] + "\n");
		}
		string line;
		while (getline(file, line)) {
			line += "\n";
			lines.push_back(line);
		}

		item = new CachedShaderObject(lines, type);
		if (!item->loaded) {
			cerr << "Shader compilation while loading:" << endl;
			for (unsigned int i = 0; i < ins.size(); ++i) {
				cerr << " " << ins[i] << endl;
			}
			if (filename != "") {
				cerr << " + file '" << filename << "'" << endl;
			}
			delete item;
			return ret;
		}

		get_cache().add_item(key.str(), item);
	}

	if (item->id != SHADEROBJECT_ID) {
		cerr << "Item with key '" << key.str() << "' already in cache and not a shader object." << endl;
		return ret;
	}

	ret.set(item);
	return ret;
}

ShaderObjectRef get_shader_object_from_text(string const &text, GLenum const type) {
	vector< string > tex;
	tex.push_back(text);
	return get_shader_object(tex, "", type);
}


CachedProgramObject::CachedProgramObject(vector< ShaderObjectRef >&_objects) : objects(_objects), handle(0) {
	id = PROGRAMOBJECT_ID;
	loaded = false;
	reload();
}

CachedProgramObject::~CachedProgramObject() {
	if (loaded) {
		if (handle != 0) {
			glDeleteObjectARB(handle);
			Graphics::gl_errors("~CachedProgramObject()");
		}
	}
}

void CachedProgramObject::reload() {
	handle = glCreateProgramObjectARB();
	for (unsigned int i = 0; i < objects.size(); ++i) {
		assert(objects[i].ref);
		assert(objects[i].ref->id == SHADEROBJECT_ID);
		if (!objects[i]->loaded) {
			objects[i]->reload();
		}
		if (!objects[i]->loaded) {
			cerr << "CachedProgramObject: Can't reload prerequisite ShaderObjects." << endl;
			return;
		}
		glAttachObjectARB(handle, objects[i]->handle);
	}
	Graphics::gl_errors("CachedProgramObject::reload @ attaching done.");
	glLinkProgramARB(handle);
	Graphics::gl_errors("CachedProgramObject::reload @ after linking.");
	GLint val = 0;
	glGetObjectParameterivARB(handle, GL_OBJECT_LINK_STATUS_ARB, &val);
	string log = shader_log(handle);
	if (val == 0) {
		cerr << "CachedProgramObject: Problem linking program." << endl;
		cerr << "Log: " << endl << log;
		return;
	}
	if (log != "") {
		cerr << "Warnings linking program:" << endl << log;
	}
	loaded = true;
	Graphics::gl_errors("ProgramShaderObject::reload");
}

ProgramObjectRef get_program_object( ShaderObjectRef &object) {
	vector< ShaderObjectRef > vec;
	vec.push_back(object);
	return get_program_object(vec);
}

ProgramObjectRef get_program_object(vector< ShaderObjectRef > &objects) {
	CacheRef< CachedProgramObject > ret(NULL);
	ostringstream key;
	key << "program:";
	//Lazy, but reasonable, way to do this:
	for (unsigned int i = 0; i < objects.size(); ++i) {
		string const *found = get_cache().get_key(objects[i].ref);
		if (!found) {
			cerr << "Bogus ShaderObjectRef in objects list -- not in cache!" << endl;
			return ret;
		}
		key << *found;
	}
	CachedProgramObject *item = (CachedProgramObject *)get_cache().get_item(key.str());
	if (!item) {
		item = new CachedProgramObject(objects);
		if (!item->loaded) {
			cerr << "Shader linking problem." << endl;
			delete item;
			return ret;
		}

		get_cache().add_item(key.str(), item);
	}

	if (item->id != PROGRAMOBJECT_ID) {
		cerr << "Item with key '" << key.str() << "' already in cache and not a program object." << endl;
		return ret;
	}

	ret.set(item);
	return ret;
}

} //namespace Graphics
