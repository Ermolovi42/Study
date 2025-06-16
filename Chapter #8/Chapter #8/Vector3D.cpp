#include <iostream>
#include "Vector3D.h"

#include "Vector3D.h"

Vector3D& Vector3D::print()
{
    std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
    return (*this);
}