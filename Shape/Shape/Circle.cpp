#include "stdafx.h"
#include "Circle.h"
#include <fstream>

CCircle::CCircle(double radius)
{
	if (radius <= 0)
	{
		throw std::domain_error("radius must be a positive number");
	}

	m_radius = radius;
}

double CCircle::GetArea() const
{
	return M_PI * pow(m_radius, 2);
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

CCircle CreateCircle(const std::pair<double, double> &centerPosition, const double radius)
{
	return CCircle(radius);
}
