#pragma once

#define CURVE_API __declspec(dllexport)


struct Vect3D {
	double x, y, z;
};

struct Pt3D {
	double x, y, z;
};

class CURVE_API CCurve
{
public:
	virtual ~CCurve();
	virtual Pt3D getPt(double t) = 0;
	virtual Vect3D getDeriv(double t) = 0;
};

class CURVE_API CCircle : public CCurve {
public:
	CCircle(double _rad);
	virtual ~CCircle();
	virtual Pt3D getPt(double t);
	virtual Vect3D getDeriv(double t);

	double m_rad;
};

class CURVE_API CEllipse : public CCurve {
public:
	CEllipse(double _radX, double _radY);

	virtual ~CEllipse();
	virtual Pt3D getPt(double t);
	virtual Vect3D getDeriv(double t);

	double m_radX;
	double m_radY;
};

class CURVE_API CHelix : public CCurve {
public:
	CHelix(double _rad, double _step);

	virtual ~CHelix();
	virtual Pt3D getPt(double t);
	virtual Vect3D getDeriv(double t);

	double m_rad;
	double m_step;
};

