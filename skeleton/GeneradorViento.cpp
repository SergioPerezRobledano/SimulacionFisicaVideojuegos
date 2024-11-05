#include "GeneradorViento.h"

void GeneradorViento::setForce()
{
	vector<Generador*>generador = particulas->getParticulas();
	std::list<Particle*>p;
	for (auto a : generador) {
		p = a->getParticulas();
		for (auto e : p) {
			e->addWForce(fuerzaViento(e));
		}
	}
}
