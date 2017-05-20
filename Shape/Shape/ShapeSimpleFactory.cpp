#include "stdafx.h"
#include "ShapeSimpleFactory.h"
#include "CircleFactorySingleton.h"
#include "RectangleFactorySingleton.h"
#include "TriangleFactorySingleton.h"

std::unique_ptr<AbstractShape> ShapeSimpleFactory::CreateShape(ShapeType type, std::vector<BigInt> params)
{
    BigInt r, a0, a1, b0, b1, c0, c1;
    if (type == ShapeType::CIRCLE && params.size() == 1)
    {
        r = params[0];
        return CircleFactorySingleton::GetInstance().CreateShape(r);
    }
    if (type == ShapeType::RECTANGLE && params.size() == 4)
    {
        a0 = params[0];
        a1 = params[1];
        b0 = params[2];
        b1 = params[3];
        return RectangleFactorySingleton::GetInstance().CreateShape(GetLength(a0, a1, b0, a1), GetLength(a0, a1, a0, b1));
    }
    if (type == ShapeType::TRIANGLE && params.size() == 6)
    {
        a0 = params[0];
        a1 = params[1];
        b0 = params[2];
        b1 = params[3];
        c0 = params[4];
        c1 = params[5];
        return TriangleFactorySingleton::GetInstance().CreateShape(GetLength(a0, a1, b0, b1), GetLength(a0, a1, c0, c1), GetLength(b0, b1, c0, c1));
    }
}

BigInt ShapeSimpleFactory::GetLength(BigInt x0, BigInt y0, BigInt x1, BigInt y1)
{
    auto sqrX = (x1 - x0) * (x1 - x0);
    auto sqrY = (y1 - y0) * (y1 - y0);
    return sqrt(sqrX + sqrY);
}
