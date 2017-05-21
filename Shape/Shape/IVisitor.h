#pragma once
#include <string>

class CCircle;
class CTriangle;
class CRectangle;

class IVisitor
{
public:
    virtual std::string Visit(const CCircle &shape) = 0;
    virtual std::string Visit(const CTriangle &shape) = 0;
    virtual std::string Visit(const CRectangle &shape) = 0;

    virtual ~IVisitor() = default;
};