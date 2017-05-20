#include "stdafx.h"
#include "CircleFactorySingleton.h"
#include "Circle.h"

std::unique_ptr<AbstractShape> CircleFactorySingleton::CreateShape(BigInt radius)
{
    return std::make_unique<CCircle>(radius);
}

CircleFactorySingleton &CircleFactorySingleton::GetInstance()
{
    static CircleFactorySingleton instance;
    return instance;
}
