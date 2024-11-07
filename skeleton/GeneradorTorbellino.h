#pragma once
#include "ForceGenerator.h"

const float coef = 0.8;

using namespace physx;
using namespace std;

class GeneradorTorbellino : public ForceGenerator
{
public:
	GeneradorTorbellino(Vector3 p, Vector3 v) :ForceGenerator(p, v) {
		intensity = 2;
	}

	Vector3 setForce(Particle* p, double t);

	Vector3 fuerzaTorbellino(Particle* p) {
		Vector3 aux = { -(p->getPos().z-initPos.z),0,p->getPos().x -initPos.x};
		return coef*((intensity *aux)-p->getVel());
	}

private:
	float intensity;
};

