#pragma once
#include "Curve.h"

class Circle : public Curve
{
	

	
	
protected:
	double radius;
	double CountX(double t) override {
		return radius * cos(t);
	}
	double CountY(double t) override {
		return radius * sin(t);
	}
	virtual double CountZ(double t) override {
		return 0;
	}
	double CountFirstDerivativeX(double t) override {
		return CountX(t);
	}
	double CountFirstDerivativeY(double t) override {
		return -1 / tan(t);
	}
	virtual double CountFirstDerivativeZ(double t) override {
		return 0;
	}
public:

	Circle() :radius(1) {  }
	Circle(double _radius) :radius(_radius){}

	double GetRadius() override{ return radius; }
	void SetRadius(double _radius) { radius = _radius; }

	Vector3D GetPoint(double t) override{
		return Vector3D(CountX(t), CountY(t), 0);
	}
	Vector3D GetFirstDerivativePoint(double t) override {
		return Vector3D(CountFirstDerivativeX(t), CountFirstDerivativeY(t), 0);
	}
	string Info() override { return "Circle"; };
};