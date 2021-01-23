#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec3 normal;
layout (location = 3) in vec2 texture;

out vec3 PositionWorld;
out vec3 VecColor;
out vec3 NormalC;
out vec3 EyeDirCamera;
out vec3 LightDirCamera;
out vec2 UV;
  
uniform mat4 MVP;
uniform mat4 V;
uniform mat4 M;
//uniform vec3 LightPosWorld;

void main()
{
    vec3 LightPosWorld = vec3(2,2,2);

    gl_Position = MVP * vec4(position , 1.0f);

    PositionWorld = (M * vec4(position,1)).xyz;
    
    vec3 PositionCamera = ( V * M * vec4(position,1)).xyz;
	EyeDirCamera = vec3(0,0,0) - PositionCamera;
    
    vec3 LightPosCamera = ( V * vec4(LightPosWorld,1)).xyz;
    LightDirCamera = LightPosCamera + EyeDirCamera;

    NormalC = ( V * M * vec4(normal,0)).xyz;

    VecColor = position;

    UV = texture;
}