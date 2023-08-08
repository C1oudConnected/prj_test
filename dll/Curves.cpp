#include "pch.h"
#include "Curves.h"

#define _USE_MATH_DEFINES
#include <math.h>

CCircle::CCircle(double _rad) : m_rad(_rad) {}

CCircle::~CCircle()
{
}

Pt3D CCircle::getPt(double t) {
    return { cos(t) * m_rad, sin(t) * m_rad, 0 };
}

Vect3D CCircle::getDeriv(double t) {
    return { cos(t) * m_rad, -1 * sin(t) * m_rad, 0 };
}

CEllipse::CEllipse(double _radX, double _radY) : m_radX(_radX), m_radY(_radY) {}

CEllipse::~CEllipse()
{
}

Pt3D CEllipse::getPt(double t) {
    return { cos(t) * m_radX, sin(t) * m_radY, 0 };
}

Vect3D CEllipse::getDeriv(double t) {
    return { cos(t) * m_radX, -1 * sin(t) * m_radY, 0 };
}

CHelix::CHelix(double _rad, double _step) : m_rad(_rad), m_step(_step) {}

CHelix::~CHelix()
{
}

Pt3D CHelix::getPt(double t)
{
    return { cos(t) * m_rad, sin(t) * m_rad, (m_step / (2 * M_PI) * t) };
}

Vect3D CHelix::getDeriv(double t)
{
    return { cos(t) * m_rad, -1 * sin(t) * m_rad, m_step / (2 * M_PI) };
}

CCurve::~CCurve()
{
}
