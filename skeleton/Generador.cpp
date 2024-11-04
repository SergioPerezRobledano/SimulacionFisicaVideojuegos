#include "Generador.h"
#include <random>

void Generador::update(double t)
{

	tiempototal += t;
	list<Particle*> p;
	Particle* aux;

	if (distribucion == GAUSS) {
		 aux = new Particle(iniPos, Vector3(generateGausssian(0.0, 2), generateGausssian(20, 2), generateGausssian(0, 2)), Vector3(0, 0, 0), 0.998);
	}
	else {
		aux = new Particle(iniPos, Vector3(generateUniform(-20,20), generateUniform(30, 40), generateUniform(0, 2)), Vector3(0, 0, 0), 0.998);
	}

	aux->settiempo(tiempototal);
	particulas.push_back(aux);
	
	p.clear();

	for (auto e : particulas) {
		e->integrate(t);
		if (tiempototal >= e->tiempo()) {
			p.push_back(e);
		}
		else {
			Vector3 lim = e->getPos() - iniPos;
			if (lim.y >= AREA_Y || lim.x >= AREA_X)p.push_back(e);
		}
	
	}

	for (auto d : p) {
		particulas.remove(d);
		delete d;
	}
}

float Generador::generateGausssian(float mean, float stddev)
{
	static std::default_random_engine generator;
	std::normal_distribution<float>distribution(mean, stddev);
	return distribution(generator);
}

float Generador::generateUniform(float min, float max)
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_real_distribution<> distrib(min, max);
	return distrib(gen);
}
