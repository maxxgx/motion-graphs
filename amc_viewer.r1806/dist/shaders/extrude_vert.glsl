void main()
{
	vec4 intermed = gl_ModelViewMatrix * gl_Vertex;
	vec4 norm = gl_ModelViewMatrix * vec4(gl_Normal,0.0);
	vec3 to_light = gl_LightSource[0].position.xyz - intermed.xyz;
	if (dot(to_light, norm.xyz) < 0.0) {
		intermed.xyz = -to_light;
		intermed.w = 0.0;
	}
	gl_Position = gl_ProjectionMatrix * intermed;
	gl_FrontColor = gl_BackColor = gl_Color;
}
