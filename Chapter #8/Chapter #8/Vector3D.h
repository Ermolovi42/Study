#pragma once

#include "Point3D.h"

class Vector3D
{
private:
	double m_x, m_y, m_z;

public:
	Vector3D(double x = 0.0, double y = 0.0, double z = 0.0)
		:m_x(x), m_y(y), m_z(z){ }

	Vector3D& print();

	friend Point3D& Point3D::moveByVector(const Vector3D &v);
};