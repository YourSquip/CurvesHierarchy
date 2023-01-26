#pragma once
#include "Circle.h"

class Helix: public Circle
{
	double step;
	double CountZ(double t) override {
		return step * t;
	}
	double CountFirstDerivativeZ(double t) override {
		return -step / (sin(t) * radius);
	}
public:
	

	Helix() :Circle(1), step(2) { }
	Helix(double _radius, double _step) :Circle(_radius), step(_step) {}

	double GetRadius() { return radius; }
	void SetRadius(double _radius) { radius = _radius; }

	double GetStep() { return step; }
	void SetStep(double _step) { radius = _step; }


	Vector3D GetPoint(double t) override {
		return Vector3D(CountX(t), CountY(t), CountZ(t));
	}
	Vector3D GetFirstDerivativePoint(double t) override {
		return Vector3D(CountFirstDerivativeX(t), CountFirstDerivativeY(t), CountFirstDerivativeZ(t));
	}
	string Info() override { return "Helix"; };

};