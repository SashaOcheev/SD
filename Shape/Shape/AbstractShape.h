#pragma once
#include "Point.h"

class AbstractShape
{
public:
	AbstractShape(const std::string &name);
	std::string GetName();
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual ~AbstractShape() = default;

protected:
    double GetLength(Point p1, Point p2);

private:
	std::string m_name;
};

