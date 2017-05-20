#include "stdafx.h"
#include "AbstractShape.h"

AbstractShape::AbstractShape(const std::string & name)
{
	m_name = name;
}

std::string AbstractShape::GetName()
{
	return m_name;
}

