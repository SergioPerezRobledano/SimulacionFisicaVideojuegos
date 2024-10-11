#pragma once
#include "Particle.h"
#include <list>
const int AREA_Y = 25, AREA_X = 10;
using namespace std;
class Generador
{
public:
	Generador(Vector3 p) :iniPos(p) {};
	~Generador();

	void update(double t);
	void destroty();
	float generateGausssian(float mean, float stddev);
private:
	Vector3 iniPos;
	list<Particle*>particulas;
};

