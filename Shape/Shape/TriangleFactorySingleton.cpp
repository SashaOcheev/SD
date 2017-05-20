#include "stdafx.h"
#include "TriangleFactorySingleton.h"
#include "Triangle.h"

std::unique_ptr<AbstractShape> TriangleFactorySingleton::CreateShape(double a, double b, double c)
{
    return std::make_unique<CTriangle>(a, b, c);
}

TriangleFactorySingleton &TriangleFactorySingleton::GetInstance()
{
    static TriangleFactorySingleton instance;
    return instance;
}
