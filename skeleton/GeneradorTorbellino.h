#pragma once
#include "ForceGenerator.h"

const float i = 1;

using namespace physx;
using namespace std;

class GeneradorTorbellino : public ForceGenerator
{
public:
	GeneradorTorbellino(Vector3 p, Vector3 v) :ForceGenerator(p, v) {
		k = 0.1;
	}

	Vector3 setForce(Particle* p);

	Vector3 fuerzaTorbellino(Particle* p) {
		Vector3 aux = Vector3(p->getPos().x, 0, -(pow(p->getPos().x, 2)) / p->getPos().z);
		return aux;
	}

private:
	Vector3 viento;
	float k;
};

