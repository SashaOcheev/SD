#pragma once
#include <memory>
#include "AbstractShape.h"

class RectangleFactorySingleton
{
public:
    std::unique_ptr<AbstractShape> CreateShape(BigInt a, BigInt b);

    static RectangleFactorySingleton &GetInstance();
private:
    RectangleFactorySingleton() = default;
    RectangleFactorySingleton(const RectangleFactorySingleton& root) = default;
    RectangleFactorySingleton& operator=(const RectangleFactorySingleton&) = default;
};
