#pragma once
#include <memory>
#include "AbstractShape.h"

class RectangleFactorySingleton
{
public:
    std::unique_ptr<AbstractShape> CreateShape(double a, double b);

    static RectangleFactorySingleton &GetInstance();
private:
    RectangleFactorySingleton() = default;
    RectangleFactorySingleton(const RectangleFactorySingleton& root) = default;
    RectangleFactorySingleton& operator=(const RectangleFactorySingleton&) = default;
};
