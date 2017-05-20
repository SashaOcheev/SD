#pragma once
#include "BigInt.h"

class AbstractShape
{
public:
	AbstractShape(const std::string &name);
	std::string GetName();
	virtual BigInt GetArea() const = 0;
	virtual BigInt GetPerimeter() const = 0;
	virtual ~AbstractShape() = default;

private:
	std::string m_name;
};

