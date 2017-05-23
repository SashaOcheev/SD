#include "stdafx.h"
#include "RectangleFactorySingleton.h"
#include "Rectangle.h"

std::unique_ptr<AbstractShape> RectangleFactorySingleton::CreateShape(BigInt a, BigInt b)
{
    return std::unique_ptr<CRectangle>(new CRectangle(a, b));
}

RectangleFactorySingleton &RectangleFactorySingleton::GetInstance()
{
    static RectangleFactorySingleton instance;
    return instance;
}
