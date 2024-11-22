#pragma once
#include"ForceGenerator.h"
class GeneradorMuelle
{
public:
	GeneradorMuelle(double K, double Rlenght, SisParticulas* s) :k(K),rlenght(Rlenght), sis(s) {
		particulas = sis->getParticulasM();
	};
	Vector3 fuerzaMuelle(Particle* p1, Particle* p2) {
		Vector3 relativePos = p1->getPos() - p2->getPos();

		const float l = relativePos.normalize();
		const float deltaX = l - rlenght;

		return  relativePos * deltaX * k;
	}
	Vector3 setForce(Particle* p1, Particle* p2, double t);
private:
	SisParticulas* sis;
	pair<Particle*, Particle*>particulas;
	double k;
	double rlenght;
};

