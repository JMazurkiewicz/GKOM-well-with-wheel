#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 3) in vec2 texture;

out vec3 PositionWorld;
out vec3 NormalC;
out vec3 LightDirCamera;
out vec2 UV;
  
uniform mat4 MVP;
uniform mat4 V;
uniform mat4 M;
uniform vec3 LightPosWorld;

void main() {
    gl_Position = MVP * vec4(position, 1.0f);

    PositionWorld = (M * vec4(position, 1.0f)).xyz;
    
    vec3 PositionCamera = (V * M * vec4(position, 1.0f)).xyz;
	vec3 EyeDirCamera = vec3(0.0f, 0.0f, 0.0f) - PositionCamera;
    
    vec3 LightPosCamera = (M * vec4(LightPosWorld, 1.0f)).xyz;
    
    LightDirCamera = LightPosCamera + EyeDirCamera;

    NormalC = (V * M * vec4(0.0f, 0.0f, 0.0f, 1.0f)).xyz;

    UV = texture;
} 
