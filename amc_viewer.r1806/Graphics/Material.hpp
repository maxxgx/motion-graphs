#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "Graphics.hpp"
#include <Vector/Vector.hpp>

namespace Graphics {
//Idea: a generic 'Material' class that does it all for the look of objects.
// something that is basic enough to handle simple colormaterial and complicated
// enough to do textures and shaders. All with a uniform interface, of course.
class BaseMaterial {
public:
	//call begin before you start outputting geometry
	virtual void begin();
	//call end... well, you get it.
	virtual void end();
/*	
	Vector4f diffuse;
	Vector4f ambient;
	Vector4f specular;
	Vector4f emission;
	float shininess;
*/
}
};

#endif //MATERIAL_HPP
