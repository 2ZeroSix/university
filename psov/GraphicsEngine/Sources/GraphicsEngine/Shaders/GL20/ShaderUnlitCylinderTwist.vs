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
void main()
{
    float angle = stage * position.y / radius * radians(180.0);
    float scale = 1.0;// - pow(radius - abs(position.y), 2.0) * stage/4.0;
    mat4 twistMat = mat4(   vec4(scale * cos(angle),    0,      sin(angle),         0.0),
                            vec4(0,                     1.0,    0,                  0.0),
                            vec4(-sin(angle),           0,      scale * cos(angle), 0.0),
                            vec4(0,                     0,      0,                  1.0));
    gl_Position = vec4(position, 1.0) * twistMat * matrixWorldViewProjT;
	gl_FrontColor = color * constColor;
}