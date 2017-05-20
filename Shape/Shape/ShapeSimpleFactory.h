#pragma once
#include <memory>
#include "AbstractShape.h"

enum class ShapeType { TRIANGLE, RECTANGLE, CIRCLE};

class ShapeSimpleFactory
{
public:
    static std::unique_ptr<AbstractShape> CreateShape(ShapeType type, double n_args...);
};

