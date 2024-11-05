#include "GeneradorGravitatorio.h"

void GeneradorGravitatorio::setForce()
{
	vector<Generador*>generador = particulas->getParticulas();
	std::list<Particle*>p;
	for (auto a : generador) {
		p=a->getParticulas();
		for (auto e : p) {
			e->addGForce(gravedad);
		}
	}
}
