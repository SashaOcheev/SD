#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(double a, double b)
	: AbstractShape("rectangle")
{
	if (a <= 0 || b <= 0)
	{
		throw std::domain_error("Rectangle's sides must be a positive numbers");
	}
	m_a = a;
	m_b = b;
}

double CRectangle::GetArea() const
{
	return m_a * m_b;
}

double CRectangle::GetPerimeter() const
{
	return 2 * (m_a + m_b);
}

CRectangle CreateRectangle(const std::pair<double, double>& leftTop, const std::pair<double, double> &rightBottom)
{
	return CRectangle(rightBottom.first - leftTop.first, rightBottom.second - leftTop.second);
}
