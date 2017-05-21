#pragma once
#include "BigInt.h"
#include "IVisitor.h"

class AbstractShape
{
public:
    virtual std::string Accept(IVisitor &visitor) = 0;
	virtual BigInt GetArea() const = 0;
	virtual BigInt GetPerimeter() const = 0;
	virtual ~AbstractShape() = default;
};

