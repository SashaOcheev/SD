#include "stdafx.h"
#include "RectangleFactorySingleton.h"
#include "Rectangle.h"

std::unique_ptr<AbstractShape> RectangleFactorySingleton::CreateShape(double a, double b)
{
    return std::make_unique<CRectangle>(a, b);
}

RectangleFactorySingleton &RectangleFactorySingleton::GetInstance()
{
    static RectangleFactorySingleton instance;
    return instance;
}
