#include "stdafx.h"
#include "ShapeSimpleFactory.h"
#include "CircleFactorySingleton.h"
#include "RectangleFactorySingleton.h"
#include "TriangleFactorySingleton.h"

std::unique_ptr<AbstractShape> ShapeSimpleFactory::CreateShape(ShapeType type, std::vector<double> params)
{
    double radius0, radius1, a0, a1, b0, b1, c0, c1;

    if (type == ShapeType::CIRCLE && params.size() == 2)
    {
        radius0 = params[0];
        radius1 = params[1];
        return CircleFactorySingleton::GetInstance().CreateShape(radius1 - radius0);
    }
    if (type == ShapeType::RECTANGLE && params.size() == 4)
    {
        a0 = params[0];
        a1 = params[1];
        b0 = params[2];
        b1 = params[3];
        return RectangleFactorySingleton::GetInstance().CreateShape(a1 - a0, b1 - b0);
    }
    if (type == ShapeType::TRIANGLE && params.size() == 6)
    {
        a0 = params[0];
        a1 = params[1];
        b0 = params[2];
        b1 = params[3];
        c0 = params[4];
        c1 = params[5];
        return TriangleFactorySingleton::GetInstance().CreateShape(a1 - a0, b1 - b0, c1 - c0);
    }
}
