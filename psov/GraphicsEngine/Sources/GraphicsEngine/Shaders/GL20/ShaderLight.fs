#version 130

struct Light
{
	vec4	typeOptions;// типозависимые опции источника
	vec4    attenuation;
	vec4	position;	// позиция источника (есть у Point и Spot)
	vec4	direction;	// направление света
	vec4	color;		// цвет.r, цвет.g, цвет.b
	vec4    specularColor; // rgb - цвет, a - сила отражения
};

// Shader parameters
uniform mat4    matWorldNormal;
uniform mat4    matWorldT;
uniform vec4    materialColor;
uniform int     lightsCount;
uniform vec4    camera;
uniform Light   lights[3];
varying vec3    localPosition;
varying vec3    localNormal;


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

void main()
{
	vec3 col = vec3(0,0,0);

	// Переводим нормаль из локальной в глобальную систему координат
	vec3 vertexNormal = (vec4(localNormal, 0.0) * matWorldNormal).xyz;
	vertexNormal = normalize(vertexNormal);
	
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
	gl_FragColor = vec4(col, 1.0);
}
