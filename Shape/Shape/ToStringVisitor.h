#pragma once
#include "IVisitor.h"
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

