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
	if (aux.first != nullptr && aux.second != nullptr) {
		v1 = Vector3(0, 0, 0);
		v2 = Vector3(0, 0, 0);
		v1 += generadoresM->fuerzaMuelle(aux.second, aux.first);
		v2 += generadoresM->fuerzaMuelle(aux.first, aux.second);
		cout << v1.y << endl;
		cout << v2.y << endl;
		aux.first->addForce(v1);
		aux.second->addForce(v2);
	}

}
