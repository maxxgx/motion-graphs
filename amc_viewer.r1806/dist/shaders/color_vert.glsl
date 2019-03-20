uniform vec4 distance_mix;

attribute vec4 distances;

void main()
{
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

	float amt = dot(distance_mix, distances);
	gl_FrontColor = vec4(amt, amt, amt, amt);
}
