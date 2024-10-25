#pragma once
#include "Particle.h"
#include <list>
const int AREA_Y = 25, AREA_X = 40;
enum tipo
{
	GAUSS, NORMAL
};
using namespace std;
class Generador
{
public:
	Generador(Vector3 p,tipo t) :iniPos(p),tiempototal(0.0),distribucion(t) {};
	~Generador() {
		for (auto e : particulas) {
			delete e;
		}
		particulas.clear();
	};

	void update(double t);
	void destroty();
	float generateGausssian(float mean, float stddev);
	float generateUniform(float min, float max);
private:
	tipo distribucion;
	Vector3 iniPos;
	list<Particle*>particulas;
	double tiempototal;
};

