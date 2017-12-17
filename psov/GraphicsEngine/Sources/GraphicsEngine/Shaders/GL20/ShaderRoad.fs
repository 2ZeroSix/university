#version 110

varying vec2 uv1;
varying vec2 uv2;
varying vec2 uv3;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform sampler2D texture3;

void main()
{
    vec2 uv1Scale = vec2(1, 100);
    vec2 uv2Scale = vec2(2, 25);
    vec2 uv3Scale = vec2(1, 5);
	vec3 color1 = texture2D( texture1, uv1.xy * uv1Scale ).rgb;
	vec3 color2 = texture2D( texture2, uv2.xy * uv2Scale ).rgb;
	vec3 color3 = texture2D( texture3, uv3.xy * uv3Scale ).rgb;
	gl_FragColor.rgb = color1 * (color2 + color3) / 2.0;
    gl_FragColor.a = 1.0;
}
