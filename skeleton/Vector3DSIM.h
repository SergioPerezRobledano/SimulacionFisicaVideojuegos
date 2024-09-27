#pragma once
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//template<class T>
class Vector3DSIM
{
protected:
	double x, y, z;
//	double modulo;

public:
	Vector3DSIM() :x(0.0), y(0.0), z(0.0) {};
	Vector3DSIM(double X, double Y, double Z) :x(X), y(Y), z(Z) {
	};


	void Normalize() {
		this->x = this->x / this->Modulo();
		this->y = this->y / this->Modulo();
		this->y = this->y / this->Modulo();
	}

	double Modulo() {
		return sqrt(pow(this->x, 2) + pow(this->y, 2)+pow(this->z,2));
	}

	double Pescalar(const Vector3DSIM& v) {
		return v.x * x + v.y * y + v.z * z;
	}


	Vector3DSIM operator +(const Vector3DSIM& v) {
		x = x + v.x;
		y = y + v.y;
		z = z + v.z;
	}

	Vector3DSIM operator -(const Vector3DSIM& v) {
		x = x - v.x;
		y = y - v.y;
		z = z - v.z;
	}
	Vector3DSIM operator =(const Vector3DSIM& p) {
		x = p.x;
		y = p.y;
		z = p.z;
		return *this;
	}
};

