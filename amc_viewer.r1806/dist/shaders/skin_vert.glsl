//const int BONES = 40; <- insert a line like this before you compile-u-late.
uniform mat4 bone_mats[BONES];

attribute vec4 bones;
attribute vec4 weights;

void main()
{
	vec4 vert_in = gl_Vertex;
	vec4 norm_in = vec4(gl_Normal, 0.0);
	ivec4 ibones = ivec4(bones);

	vec4 vert;
	vec4 norm;
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

	//Finally, model view transform:
	vert = gl_ModelViewMatrix * vert;
	norm = normalize(gl_ModelViewMatrix * norm);

	//some basic lighting:
	vec3 lightdir = normalize(gl_LightSource[0].position.xyz - vert.xyz);
	float light = max(dot(norm.xyz, lightdir), 0.0);

	//output ye olde vert:
	gl_FrontColor = (gl_LightSource[0].diffuse * light + gl_LightSource[0].ambient) * gl_Color;

	gl_Position = gl_ProjectionMatrix * vert;
}
