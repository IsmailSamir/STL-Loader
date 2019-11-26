//#include <vld.h>

#include <STL/STL.h>

int
main(int argc, char** argv)
{	
	const char* filepath = "D:/1.stl";

	stl::STL self = stl::stl_read_binary(filepath);
	return 0;
}