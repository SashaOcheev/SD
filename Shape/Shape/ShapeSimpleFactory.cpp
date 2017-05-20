#include "stdafx.h"
#include "ShapeSimpleFactory.h"
#include "CircleFactorySingleton.h"
#include "RectangleFactorySingleton.h"
#include "TriangleFactorySingleton.h"
#include <stdarg.h> 

std::unique_ptr<AbstractShape> ShapeSimpleFactory::CreateShape(ShapeType type, double n_args ...)
{
    va_list params;
    va_start(params, n_args);
    if (type == ShapeType::CIRCLE)
    {
        double radius = va_arg(params, double);
        return CircleFactorySingleton::GetInstance().CreateShape(radius);
    }
    else if (type == ShapeType::RECTANGLE)
    {
        double a = va_arg(params, double);
        double b = va_arg(params, double);
        return RectangleFactorySingleton::GetInstance().CreateShape(a, b);
    }
    else if (type == ShapeType::TRIANGLE)
    {
        double a = va_arg(params, double);
        double b = va_arg(params, double);
        double c = va_arg(params, double);
        return TriangleFactorySingleton::GetInstance().CreateShape(a, b, c);
    }
    va_end(params);
}
