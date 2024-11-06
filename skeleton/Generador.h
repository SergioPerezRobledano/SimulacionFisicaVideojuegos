#pragma once
#include "Particle.h"
#include <list>
const int AREA_Y = 100, AREA_X = 100;
enum tipo
{
	GAUSS, NORMAL
};
using namespace std;
class Generador
{
public:
	Generador(Vector3 p,tipo t) :iniPos(p),tiempototal(0.0),distribucion(t) {

	};
	~Generador() {
		for (auto e : particulas) {
			delete e;
		}
		particulas.clear();
	};

	void Generate(double t);

	void Integrate(double t);

	void update(double t);

	float generateGausssian(float mean, float stddev);
	float generateUniform(float min, float max);

	list<Particle*> getParticulas() { return particulas; }

private:
	tipo distribucion;
	Vector3 iniPos;
	list<Particle*>particulas;
	double tiempototal;
};

