void main()
{
	vec4 vert = gl_ModelViewMatrix * gl_Vertex;
	vec4 norm = normalize(gl_ModelViewMatrix * vec4(gl_Normal,0.0));
	vec3 lightdir = normalize(gl_LightSource[0].position.xyz - vert.xyz);

	float light = max(dot(norm.xyz, lightdir), 0.0);
	gl_FrontColor = (gl_LightSource[0].diffuse * light + gl_LightSource[0].ambient) * gl_Color;

	gl_Position = gl_ProjectionMatrix * vert;
}
