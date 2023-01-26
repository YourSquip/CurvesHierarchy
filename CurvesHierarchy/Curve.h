#pragma once
#include <cmath>
#include <string>
#include <iostream>
using std::string;
#include "Vector3D.h"
const double PI = 3.14159265359;
class Curve
{
public:
	virtual double CountX(double t) = 0;
	virtual double CountY(double t) = 0;
	virtual double CountZ(double t) = 0;

	virtual double CountFirstDerivativeX(double t) = 0;
	virtual double CountFirstDerivativeY(double t) = 0;
	virtual double CountFirstDerivativeZ(double t) = 0;

	virtual Vector3D GetPoint(double t) = 0;
	virtual Vector3D GetFirstDerivativePoint(double t) = 0;

	virtual string Info() = 0;
	virtual double GetRadius() = 0;
};