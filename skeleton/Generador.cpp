#include "Generador.h"
#include <random>

void Generador::update(double t)
{
	list<Particle*> p;
	particulas.push_back(new Particle(iniPos, Vector3(generateGausssian(0.0,2), generateGausssian(20, 2), generateGausssian(0, 2)), Vector3(0, -9.8, 0), 0.998));
	for (auto e : particulas) {
		e->integrate(t);
	Vector3 lim = e->getPos() - iniPos;
		if (lim.y >= AREA_Y || lim.x >= AREA_X)p.push_back(e);
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
