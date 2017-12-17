#version 110

attribute vec3 position;
attribute vec4 color;
attribute vec3 normal;
attribute vec3 texcoord0;

uniform mat4 matrixWorldViewProjT;

varying vec2 uv1;
varying vec3 localPosition;
varying vec3 localNormal;
void main()
{
	gl_Position		= vec4(position, 1.0) * matrixWorldViewProjT;
	gl_FrontColor	= color;
	localPosition	= position;
	uv1				= texcoord0.xy;
	localNormal		= normal;
}