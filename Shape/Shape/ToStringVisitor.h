#pragma once
#include "IVisitor.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

class ToStringVisitor :
    public IVisitor
{
public:
    ToStringVisitor();

    std::string Visit(const CCircle &shape) override;
    std::string Visit(const CTriangle &shape) override;
    std::string Visit(const CRectangle &shape) override;

    ~ToStringVisitor();
};

