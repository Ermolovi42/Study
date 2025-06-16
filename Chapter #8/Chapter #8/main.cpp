#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <vector>
#include <array>
#include <utility>
#include <cassert>
#include <sstream>
#include <cstdarg>
#include <cstdint>
#include "Vector3D.h"
#include "Point3D.h"

int main()
{
	Point3D  p(3.0, 4.0, 5.0);
	Vector3D v(3.0, 3.0, -2.0);

	p.print().moveByVector(v).print();

	return 0;
}
