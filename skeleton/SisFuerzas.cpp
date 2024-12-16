#include "SisFuerzas.h"
#include<list>
#include<iostream>

void SisFuerzas::update(double t)
{

	Vector3 v,m;
	list<Particle*> aux = sisparticulas->getParticulas();
	for (auto p : aux) {
		v = Vector3(0, 0, 0);
		for (auto g : generadores) {
			v += g->setForce(p,t);
		}
		//std::cout << v.x << " " << v.y << " " << v.z << endl;
		p->addForce(v);
	}
	list<Particle*> Vaux = sisparticulas->getVParticulas();
	for (auto p : Vaux) {
		m = Vector3(0, 0, 0);
		if (viento != nullptr) {
			m += viento->setForce(p, t);
			p->addForce(m);
		}

		//std::cout << v.x << " " << v.y << " " << v.z << endl;

	}
}

void SisFuerzas::updatesolidos(double t)
{
	Vector3 v;
	list<SolidoRigido*> aux = sissolidos->getSolidos();
	for (auto p : aux) {
		v = Vector3(0, 0, 0);
		for (auto g : generadores) {
			v += (g->setForce(p, t));
		}
		//std::cout << v.x << " " << v.y << " " << v.z << endl;
		p->setForce(v);
	}
	Vector3 w;
	list<SolidoRigido*> Maux = sissolidos->getMSolidos();
	for (auto p : Maux) {
		w = Vector3(0, 0, 0);
		if (mAnclado != nullptr) {
			w = mAnclado->setForce(p, t)*1000;
			std::cout << w.x << " " << w.y << " " << w.z << endl;
		}
		
		p->setForce(w);
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
