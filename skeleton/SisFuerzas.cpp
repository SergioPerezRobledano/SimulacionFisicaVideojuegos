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
			v += g->setForce(p,t);
		}
		std::cout << v.x << " " << v.y << " " << v.z << endl;
		p->addForce(v);
	}
}

void SisFuerzas::updateMuelles(double t)
{
	Vector3 v1,v2;
	pair<Particle*, Particle*> aux = sisparticulas->getParticulasM();
		v1 = Vector3(0, 0, 0);
		v2 = Vector3(0, 0, 0);
		v1 += generadoresM->setForce(aux.second, t);
		v2 += generadoresM->setForce(aux.first, t);

		aux.first->addForce(v1);
		aux.second->addForce(v2);
}
