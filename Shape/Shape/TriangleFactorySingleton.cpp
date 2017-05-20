#include "stdafx.h"
#include "TriangleFactorySingleton.h"
#include "Triangle.h"

std::unique_ptr<AbstractShape> TriangleFactorySingleton::CreateShape(BigInt a, BigInt b, BigInt c)
{
    return std::make_unique<CTriangle>(a, b, c);
}

TriangleFactorySingleton &TriangleFactorySingleton::GetInstance()
{
    static TriangleFactorySingleton instance;
    return instance;
}
