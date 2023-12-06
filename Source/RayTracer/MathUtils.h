#pragma once
#include <glm/glm.hpp>

//#define FLT_EPSILON      1.192092896e-07F

template <typename T>
inline T lerp(const T& a, const T& b, float t)
{
	return  (a * (1 - t)) + (t * b);
}

inline glm::vec3 cross(const glm::vec3& v1, const glm::vec3& v2)
{
	return glm::cross(v1, v2);//glm::vec3(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);//
}

inline float dot(const glm::vec3& v1, const glm::vec3& v2)
{
	return glm::dot(v1, v2); //(v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);//
}

inline float angle(const glm::vec3& v1, const glm::vec3& v2)
{
	return glm::acos(dot(v1, v2));
}

inline glm::vec3 reflect(const glm::vec3& v, const glm::vec3& n)
{
	
	return glm::reflect(v, n);//v - 2.0f * dot(n,v) * n;//v - (n * dot(n, v)) * 2.0f//
}

inline bool approximately(float value1, float value2)
{
	// check if the difference between the values is less than epsilon
	return glm::abs(value1 - value2) < FLT_EPSILON;
}