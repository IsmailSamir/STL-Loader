#pragma once

#include "STL/Exports.h"

#include <string>
#include <vector>

namespace stl
{
	typedef struct Vec3
	{
		float x;
		float y;
		float z;
	}vec3;

	struct Triangle_Face
	{
		vec3 normal;
		vec3 points[3];
	};

	struct STL
	{
		char name[80];
		std::vector<Triangle_Face> triangles;
	};


	STL_EXPORT STL
	stl_read_binary(std::string filepath);
}