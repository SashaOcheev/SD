#pragma once
#include <memory>
#include "AbstractShape.h"
#include <vector>

enum class ShapeType { TRIANGLE, RECTANGLE, CIRCLE};

class ShapeSimpleFactory
{
public:
    static std::unique_ptr<AbstractShape> CreateShape(ShapeType type, std::vector<double> params);
};

