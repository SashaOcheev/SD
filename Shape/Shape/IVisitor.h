#pragma once
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <string>

class IVisitor
{
public:
    virtual std::string Visit(const CCircle &shape) = 0;
    virtual std::string Visit(const CTriangle &shape) = 0;
    virtual std::string Visit(const CRectangle &shape) = 0;

    virtual ~IVisitor() = default;
};