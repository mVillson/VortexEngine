#version 330 core

in vec2 vTexCoord;

out vec4 Color;

uniform vec4 uColor;
uniform sampler2D uTexture;

void main()
{
	vec4 TexColor = texture(uTexture, vTexCoord);
	Color = TexColor;
}