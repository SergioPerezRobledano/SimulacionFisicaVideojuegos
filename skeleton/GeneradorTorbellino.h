#pragma once
#include "ForceGenerator.h"

const float i = 1;

using namespace physx;
using namespace std;

class GeneradorTorbellino : public ForceGenerator
{
public:
	GeneradorTorbellino(Vector3 p, Vector3 v) :ForceGenerator(p, v) {
		k = 3;
	}

	Vector3 setForce(Particle* p);

	Vector3 fuerzaTorbellino(Particle* p) {
		Vector3 aux = {
		-(p->getPos().z - initPos.z),
		0,						// Preguntar que narices poner aqui
		p->getPos().z - initPos.x
		};
		return (k*aux)-p->getVel();
	}

private:
	Vector3 viento;
	float k;
};

