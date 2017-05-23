#pragma once
#include <memory>
#include "AbstractShape.h"

class CircleFactorySingleton
{
public:
    std::unique_ptr<AbstractShape> CreateShape(BigInt radius);

    static CircleFactorySingleton &GetInstance();

private:
    CircleFactorySingleton() = default;
    CircleFactorySingleton(const CircleFactorySingleton& root) = default;
    CircleFactorySingleton& operator=(const CircleFactorySingleton&) = default;
};
