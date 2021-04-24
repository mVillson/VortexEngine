#version 330 core

out vec4 Color;

in vec2 vTexCoord;

uniform vec4 uColor;
uniform sampler2D uTexture;

void main()
{
	vec4 TexColor = texture(uTexture, vTexCoord);
	Color = TexColor;
}