#include "SisFuerzas.h"
#include<list>
#include<iostream>

void SisFuerzas::update(double t)
{

	Vector3 v;
	list<Particle*> aux = sisparticulas->getParticulas();
	for (auto p : aux) {
		v = Vector3(0, 0, 0);
		for (auto g : generadores) {
			v += g->setForce(p);
		}
		std::cout << v.x << " " << v.y << " " << v.z << endl;
		p->addForce(v);
	}
}
