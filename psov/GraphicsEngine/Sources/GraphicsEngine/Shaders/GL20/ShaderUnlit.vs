#version 110

// Vertex structure
// Set order of vertex structure (position, color)
// Search in C++ code funciton GL20Mesh::Render()
// glVertexAttribPointer(0, ...) // this is "position"
// glVertexAttribPointer(1, ...) // this is "color"
attribute vec3 position;
attribute vec4 color;

// Shader parameters
// Search in C++ code functions like "glUniform4"
// i.e. functions: glUniform4fv(), glUniformMatrix4fv().
// These functions pass to shader parameters listed below
uniform vec4 constColor;
uniform mat4 matrixWorldViewProjT;
uniform float stage;
uniform float radius;
uniform int transform;
void main()
{
	if (transform == 0) {
	    vec3 sphereCoord = radius * normalize(position);
	    gl_Position = vec4(mix(position, sphereCoord, stage), 1.0) * matrixWorldViewProjT;
	} else if (transform == 1) {
        float angle = position.y * stage * radians(180.0);
        float scale = pow(1.0 - abs((radius - abs(position.y)) * stage * stage), 2.0);
        mat4 twistMat = mat4(   vec4(scale * cos(angle),    0,      sin(angle),         0.0),
                                vec4(0,                     1,      0,                  0.0),
                                vec4(-sin(angle),           0,      scale * cos(angle), 0.0),
                                vec4(0,                     0,      0,                  1.0));
	    gl_Position = vec4(position, 1.0) * twistMat * matrixWorldViewProjT;
	} else {
	    gl_Position = vec4(position, 1.0);
	}
	gl_FrontColor = color * constColor;
}