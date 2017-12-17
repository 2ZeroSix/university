#version 110

struct Light
{
	vec4	typeOptions;// типозависимые опции источника
	vec4    attenuation;
	vec4	position;	// позиция источника (есть у Point и Spot)
	vec4	direction;	// направление света
	vec4	color;		// цвет.r, цвет.g, цвет.b
	vec4    specularColor; // rgb - цвет, a - сила отражения
};


uniform sampler2D texture1;
uniform sampler2D texture2;
uniform mat4    matWorldNormal;
uniform mat4    matWorldT;
uniform int     lightsCount;
uniform vec4    camera;
uniform Light   lights[3];
varying vec3    localPosition;
varying vec3    localNormal;

varying vec2 uv1;

vec3 calcDiffuse(vec3 lightDir, vec3 lightCol, vec3 vertexNormal, float intensity)
{
	float diffuse = clamp( dot(-lightDir, vertexNormal), 0.0, 1.0 ) * intensity;

	// Цвет = diffuse * (цвет источника) * (интенсивность источника)
	vec3 color = diffuse * lightCol;

	return color;
}

vec3 calcSpecular(vec4 specLightCol, vec3 lightDir, vec3 vertexPos, vec3 vertexNormal, float intensity) {
    vec3 halfway = normalize(normalize(camera.xyz - vertexPos) - lightDir);
    float specular = pow(clamp(dot(vertexNormal.xyz, halfway), 0.0, 1.0), specLightCol.w) * intensity;
    vec3 color = specular * specLightCol.xyz;
    return color;
}

vec3 calcColor(vec3 materialColor, vec3 vertexNormal) {
	vec3 col = vec3(0,0,0);


	// Переводим позицию из локальной в глобальную систему координат
	vec3 vertexPos = (vec4(localPosition, 1.0) * matWorldT).xyz;

	for (int i = 0; i < lightsCount; ++i) {
		float type = (lights[i].typeOptions.x);
		float epsilon = 0.001;
		vec3 lightDir = vec3(0,0,0);
	    float intensity = 1.0;
		// Directional light
        if (abs(type - 1.0) < epsilon) {
			lightDir = normalize(lights[i].direction.xyz);
		}
		// Point light
        else if (abs(type - 2.0) < epsilon) {
			lightDir = normalize(vertexPos - lights[i].position.xyz);
			float dist = length(vertexPos - lights[i].position.xyz);
			vec3 atten = lights[i].attenuation.xyz;
			intensity /= atten.x + (atten.y + atten.z * dist) * dist;
		}
		// Spot light
		else if (abs(type - 3.0) < epsilon) {
			lightDir = normalize(vertexPos - lights[i].position.xyz);
			float cosTheta2 = lights[i].typeOptions.y;
			float cosPhi2 = lights[i].typeOptions.z;
			float falloff = lights[i].typeOptions.w;
			float cosAngle = dot(lightDir, normalize(lights[i].direction.xyz));
			if (cosTheta2 > cosAngle && cosAngle >= cosPhi2) {
			    intensity = pow((cosAngle - cosPhi2) / (cosTheta2 - cosPhi2), falloff);
                float dist = length(vertexPos - lights[i].position.xyz);
                vec3 atten = lights[i].attenuation.xyz;
                intensity /= atten.x + (atten.y + atten.z * dist) * dist;
			} else if (cosPhi2 > cosAngle) {
			    intensity = 0.0;
			} else {
                float dist = length(vertexPos - lights[i].position.xyz);
                vec3 atten = lights[i].attenuation.xyz;
                intensity /= atten.x + (atten.y + atten.z * dist) * dist;
			}
		}

		col += materialColor.rgb * calcDiffuse(lightDir, lights[i].color.xyz, vertexNormal, intensity);
		col += calcSpecular(lights[i].specularColor, lightDir, vertexPos, vertexNormal, intensity);
	}
	return col;
}

void main()
{
    vec2 uv1Scale = vec2(1, 1);
	vec3 color = texture2D( texture1, uv1.xy * uv1Scale ).rgb;

	vec3 vertexNormal = normalize((vec4(localNormal, 1.0) * matWorldNormal).xyz);
	vec3 nloc = texture2D( texture2, uv1.xy * uv1Scale ).rgb * vec3(2.0,2.0,2.0) - vec3(1.0, 1.0, 1.0);
	vec3 t = cross(vertexNormal , vec3(1,1,1));
	vec3 b = cross(vertexNormal , t);
	vec3 normal = normalize(nloc.x * t + nloc.y * b + nloc.z * vertexNormal);

	gl_FragColor = vec4(calcColor(color, normal), 1.0);
}
