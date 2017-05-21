#include "stdafx.h"
#include "Circle.h"
#include <fstream>

CCircle::CCircle(BigInt radius)
{
	if (radius <= 0)
	{
		throw std::domain_error("radius must be a positive number");
	}

	m_radius = radius;
}

std::string CCircle::Accept(IVisitor & visitor)
{
    return visitor.Visit(*this);
}

BigInt CCircle::GetArea() const
{
	return m_radius * m_radius * M_PI;
}

BigInt CCircle::GetPerimeter() const
{
	return m_radius * 2 * M_PI;
}

