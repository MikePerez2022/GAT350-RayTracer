#pragma once
#include <cmath>
#include <glm/glm.hpp>


using color3_t = glm::vec3;
using color4_t = glm::vec4;
using rgba_t = glm::uint32_t;

inline color4_t RGBAToColor(const rgba_t& rgba)
{
	//convert r,g,b,a values individually to int then divide by 255 to clamp it to 0-1 float range
	float red = (float)((rgba >> 24) & 255) / 255.0f;
	float green = (float)((rgba >> 16) & 255) / 255.0f;
	float blue = (float)((rgba >> 8) & 255) / 255.0f;
	float alpha = (float)(rgba & 255) / 255.0f;

	//make color4 and return it
	return color4_t(red, green, blue, alpha);
}

inline rgba_t ColorToRGBA(const color4_t& color)
{
	//convert the float back to int use round function to make it more accurate
	int red = (int)(std::round(color.r * 255));
	int green = (int)(std::round(color.g * 255));
	int blue = (int)(std::round(color.b * 255));
	int alpha = (int)(std::round(color.a * 255));

	//make rgba with the bits in the right places and return it
	return rgba_t((red << 24) | (green << 16) | (blue << 8) | alpha);
}