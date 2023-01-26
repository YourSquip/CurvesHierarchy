#pragma once
#include <iostream>
class Vector3D
{
	double x=0, y=0, z=0;

public:

	Vector3D() : x(0), y(0), z(0) {}
	Vector3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

	double GetX() { return x; }
	double GetY() { return y; }
	double GetZ() { return z; }

	void SetX(double _x) { x = _x; }
	void SetY(double _y) { y = _y; }
	void SetZ(double _z) { z = _z; }

	void print() { std::cout << x << ' ' << y << ' ' << z << ' '<<std::endl; }

};