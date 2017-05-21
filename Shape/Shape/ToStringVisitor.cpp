#include "stdafx.h"
#include "ToStringVisitor.h"


ToStringVisitor::ToStringVisitor()
{
}

std::string ToStringVisitor::Visit(const CCircle & shape)
{
    return "CIRCLE P=" + shape.GetPerimeter().ToString() + " S=" + shape.GetArea().ToString();
}

std::string ToStringVisitor::Visit(const CTriangle & shape)
{
    return "TRIANGLE P=" + shape.GetPerimeter().ToString() + " S=" + shape.GetArea().ToString();
}

std::string ToStringVisitor::Visit(const CRectangle & shape)
{
    return "RECTANGLE P=" + shape.GetPerimeter().ToString() + " S=" + shape.GetArea().ToString();
}

ToStringVisitor::~ToStringVisitor()
{
}
