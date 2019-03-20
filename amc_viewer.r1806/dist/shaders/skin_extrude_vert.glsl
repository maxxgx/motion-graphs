//const int BONES = 40; <- insert a line like this before you compile-u-late.
uniform mat4 bone_mats[BONES];

attribute vec4 bones;
attribute vec4 weights;

void main()
{

	vec4 vert;
	vec4 norm;
	{ //transform scoped, for some reason:
		vec4 vert_in = gl_Vertex;
		vec4 norm_in = vec4(gl_Normal, 0.0);
		ivec4 ibones = ivec4(bones);
		{
			mat4 bone1 = bone_mats[ibones.x];
			vert = (bone1 * vert_in) * weights.x;
			norm = (bone1 * norm_in) * weights.x;
		}
		{
			mat4 bone2 = bone_mats[ibones.y];
			vert += (bone2 * vert_in) * weights.y;
			norm += (bone2 * norm_in) * weights.y;
		}
		{
			mat4 bone3 = bone_mats[ibones.z];
			vert += (bone3 * vert_in) * weights.z;
			norm += (bone3 * norm_in) * weights.z;
		}
		{
			mat4 bone4 = bone_mats[ibones.w];
			vert += (bone4 * vert_in) * weights.w;
			norm += (bone4 * norm_in) * weights.w;
		}
	}

	//Finally, model view transform:
	vert = gl_ModelViewMatrix * vert;
	norm = gl_ModelViewMatrix * norm;

	vec4 from_light = vec4(vert.xyz - gl_LightSource[0].position.xyz, 0.0);
	
	vert = vert + mix(vert, from_light, step(0.0, dot(from_light, norm)));

	gl_Position = gl_ProjectionMatrix * vert;
	gl_FrontColor = gl_BackColor = gl_Color;
}
