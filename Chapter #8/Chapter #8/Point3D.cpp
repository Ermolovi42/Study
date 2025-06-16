#include <iostream>
#include "Point3D.h"
#include "Vector3D.h"

Point3D& Point3D::print()
{
	std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";

	return (*this);
}

Point3D& Point3D::moveByVector(const Vector3D& v)
{
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
	return (*this);
}
