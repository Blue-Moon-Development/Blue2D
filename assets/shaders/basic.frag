#version 330

in vec3 vertColor;

out vec4 fragColor;

uniform float sinTime;
uniform float cosTime;

void main()
{
    fragColor = vec4(vertColor.r * sinTime, vertColor.g * cosTime, vertColor.b, 1.0);
}
