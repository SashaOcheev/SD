#pragma once
#include <memory>
#include "AbstractShape.h"

class TriangleFactorySingleton
{
public:
    std::unique_ptr<AbstractShape> CreateShape(BigInt a, BigInt b, BigInt c);

    static TriangleFactorySingleton &GetInstance();

private:
    TriangleFactorySingleton() = default;
    TriangleFactorySingleton(const TriangleFactorySingleton& root) = default;
    TriangleFactorySingleton& operator=(const TriangleFactorySingleton&) = default;
};
