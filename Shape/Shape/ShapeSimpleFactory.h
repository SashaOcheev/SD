#pragma once
#include <memory>
#include "AbstractShape.h"
#include <vector>

enum class ShapeType { TRIANGLE, RECTANGLE, CIRCLE};

class ShapeSimpleFactory
{
public:
    static std::unique_ptr<AbstractShape> CreateShape(ShapeType type, std::vector<BigInt> params);

private:
    static BigInt GetLength(const BigInt &x0, const BigInt &y0, const BigInt &x1, const BigInt &y1);
};

