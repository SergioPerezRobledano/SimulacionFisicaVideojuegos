#pragma once
#include "Particle.h"
#include "SolidoRigido.h"
#include <list>
const int AREA_Y = 10000, AREA_X = 10000;
enum tipo
{
	GAUSS, NORMAL, TRAYECTORIA
};

using namespace std;
class Generador
{
public:
	Generador(Vector3 p,tipo t,SolidoRigido* b,double s) :iniPos(p),tiempototal(0.0),distribucion(t),ball(b),spawn(s) {
		tiempogeneracion = 0.0;
		generar = true;
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

	void reset();

	float generateGausssian(float mean, float stddev);
	float generateUniform(float min, float max);

	list<Particle*> getParticulas() { return particulas; }

	void parar(bool t) {
		generar = t;
	}

private:
	bool generar;
	tipo distribucion;
	Vector3 iniPos;
	list<Particle*>particulas;
	double tiempototal;
	double tiempogeneracion;
	double spawn;
	SolidoRigido* ball;
};

