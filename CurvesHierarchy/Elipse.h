#pragma once
#include "Curve.h"

class Elipse : public Curve
{
	double radiusOX, radiusOY;

	double CountX(double t) override {
		return radiusOX * cos(t);
	}
	double CountY(double t) override {
		return radiusOY * sin(t);
	}
	double CountZ(double t) override {
		return 0;
	}
	double CountFirstDerivativeX(double t) override {
		return CountX(t);
	}
	double CountFirstDerivativeY(double t) override {
		return -(radiusOX*radiusOY) / tan(t);
	}
	double CountFirstDerivativeZ(double t) override {
		return 0;
	}
	double GetRadius() override { return radiusOX; }
public:

	Elipse() :radiusOX(1), radiusOY(2) {  }
	Elipse(double _radiusOX, double _radiusOY) :radiusOX(_radiusOX),radiusOY(_radiusOY) {}

	double GetOXRadius() { return radiusOX; }
	double GetOYRadius() { return radiusOY; }
	void SetOXRadius(double _radiusOX) { radiusOX = _radiusOX; }
	void SetOYRadius(double _radiusOY) { radiusOY = _radiusOY; }

	Vector3D GetPoint(double t) override {
		return Vector3D(CountX(t), CountY(t), 0);
	}
	Vector3D GetFirstDerivativePoint(double t) override {
		return Vector3D(CountFirstDerivativeX(t), CountFirstDerivativeY(t), 0);
	}
	string Info() override { return "Elipse"; };
};