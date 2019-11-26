#include "STL/STL.h"

#include <fstream>
#include <assert.h>

using namespace std;

namespace stl
{
	inline static vec3
	_parse_point(const char* triangle_face)
	{
		char x[4] = { triangle_face[0], triangle_face[1], triangle_face[2], triangle_face[3] };
		char y[4] = { triangle_face[4], triangle_face[5], triangle_face[6], triangle_face[7] };
		char z[4] = { triangle_face[8], triangle_face[9], triangle_face[10], triangle_face[11] };
		
		vec3 self{};

		self.x = *((float*)x);
		self.y = *((float*)y);
		self.z = *((float*)z);

		return self;
	}

	STL
	stl_read_binary(std::string filepath)
	{
		STL self{};

		ifstream file(filepath.c_str(), ios::in | ios::binary);

		// if faild to open file
		if (!file)
		{
			assert(false && "Faild to open file");
			return STL{};
		}

		// read the name of the mesh
		file.read(self.name, 80);

		// read number of traiangles
		char ntriangles[4];
		file.read(ntriangles, 4);
		uint32_t triangles = *((uint32_t*)ntriangles);

		char bag[50];
		// reda normals and points for each triangle
		for (int i = 0; i < triangles; ++i)
		{
			file.read(bag, 50);
			
			Triangle_Face triangle{};
			
			triangle.normal = _parse_point(bag);

			triangle.points[0] = _parse_point(bag + 12);
			triangle.points[1] = _parse_point(bag + 24);
			triangle.points[2] = _parse_point(bag + 36);

			self.triangles.push_back(triangle);
		}

		return self;
	}
}