#include "stdafx.h"
#include "AbstractShape.h"

AbstractShape::AbstractShape(const std::string & name)
{
	m_name = name;
}

std::string AbstractShape::GetName()
{
	return m_name;
}

double AbstractShape::GetLength(Point p1, Point p2)
{
    auto sqrX = (p2.x - p1.x) * (p2.x - p1.x);
    auto sqrY = (p2.y - p2.y) * (p2.y - p1.y);
    auto sqrSum = sqrX + sqrY;
    return pow(sqrSum, 0.5);
}
