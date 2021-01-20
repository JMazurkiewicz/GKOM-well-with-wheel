#version 330 core
in vec3 PositionWorld;
in vec3 VecColor;
in vec3 NormalC;
in vec3 EyeDirCamera;
in vec3 LightDirCamera;

out vec3 color;


void main()
{
	vec3 LightColor = vec3(1,1,1);
	float LightPower = 50.0f;
    vec3 LightPosWorld = vec3(3,3,3);
	
	vec3 MaterialDiffuseColor = VecColor;
	vec3 MaterialAmbientColor = vec3(0.1,0.1,0.1) * MaterialDiffuseColor;
	
	float distance = length(LightPosWorld - PositionWorld);
	
	vec3 n = normalize(NormalC);
	
	vec3 l = normalize(LightDirCamera);
	
	float cosTheta = clamp( dot(n,l), 0,1 );

    color = MaterialDiffuseColor * LightColor * LightPower * cosTheta / (distance*distance)
	+ MaterialAmbientColor;
}
