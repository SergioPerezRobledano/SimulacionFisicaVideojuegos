#pragma once
#include"ForceGenerator.h"
class GeneradorMuelleAnclado: public ForceGenerator
{
public:
	GeneradorMuelleAnclado(double K, double Rlenght) :ForceGenerator(),k(K), rlenght(Rlenght){
		other = new Particle({ 0.0,50.0,0.0 }, { 0.0,0.0,0.0, }, { 0.0,0.0,0.0, }, 0.85, 60,CreateShape(PxBoxGeometry(1,1,1)),{1,1,0,0});
	};
	virtual Vector3 fuerzaMuelle(Particle* p) {
		Vector3 relativePos = other->getPos() - p->getPos();

		const float l = relativePos.normalize();
		const float deltaX = l - rlenght;

		return  relativePos * deltaX * k;
	}
	virtual Vector3 setForce(Particle* p, double t);

protected:
	Particle* other;
	double k;
	double rlenght;
};

