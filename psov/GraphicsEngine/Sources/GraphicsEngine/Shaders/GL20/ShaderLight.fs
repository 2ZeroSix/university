#version 110

struct Light
{
	vec4	typeOptions;// типозависимые опции источника
	vec4	position;	// позиция источника (есть у Point и Spot)
	vec4	direction;	// направление света
	vec4	color;		// (цвет.r, цвет.g, цвет.b, интенсивность)
};

// Shader parameters
uniform mat4    matWorldNormal;
uniform mat4    matWorldT;
uniform vec4    materialColor;
uniform int     lightsCount;
uniform Light   lights[3];

varying vec3 localPosition;
varying vec3 localNormal;


vec3 calcDiffuse(vec4 lightCol, vec3 lightDir, vec3 vertexNormal)
{
	float diffuse = clamp( dot(-lightDir, vertexNormal), 0.0, 1.0 );

	// Цвет = diffuse * (цвет источника) * (интенсивность источника)
	vec3 color = diffuse * lightCol.rgb * lightCol.a;

	return color;
}

//vec3 calcSpecular(vec4 lightCol, vec3 lightDir, )
void main()
{
	vec3 col = vec3(0,0,0);

	// Переводим нормаль из локальной в глобальную систему координат
	vec3 vertexNormal = (vec4(localNormal, 0.0) * matWorldNormal).xyz;
	vertexNormal = normalize(vertexNormal);
	
	// Переводим позицию из локальной в глобальную систему координат
	vec3 vertexPos = (vec4(localPosition, 1.0) * matWorldT).xyz;
	
	for (int i = 0; i < lightsCount; ++i) {
		float type = lights[i].typeOptions.x;
		float epsilon = 0.001;
		
		vec4 lightCol = lights[i].color;
		vec3 lightDir = vec3(0,0,0);
	
		// Directional light
        if (abs(type - 1.0) < epsilon) {
			lightDir = normalize(lights[i].direction.xyz);
		}
		// Point light
        else if (abs(type - 2.0) < epsilon) {
			lightDir = normalize(vertexPos - lights[i].position.xyz);
		}
		// Spot light
		else if (abs(type - 3.0) < epsilon) {
			lightDir = normalize(vertexPos - lights[i].position.xyz);
			float cosTheta2 = lights[i].typeOptions.y;
			float cosPhi2 = lights[i].typeOptions.z;
			float falloff = lights[i].typeOptions.w;
			float cosAngle = dot(lightDir, normalize(lights[i].direction.xyz));
			if (cosAngle >= cosTheta2) {
			    // nothing
			} else if (cosAngle >= cosPhi2) {
			    float intensivity = pow((cosAngle - cosPhi2) / (cosTheta2 - cosPhi2), falloff);
			    lightCol *= intensivity;
			} else {
			    lightCol = vec4(0.0, 0.0, 0.0, 1.0);
			}
		}

		col += materialColor.rgb * calcDiffuse(lightCol, lightDir, vertexNormal);
	}
	
	gl_FragColor = vec4(col, 1.0);
        gl_FragColor.a = 1.0;
}
