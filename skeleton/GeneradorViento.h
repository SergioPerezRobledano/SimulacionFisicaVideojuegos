#pragma once
#include "ForceGenerator.h"

const float u = 0.9;

class GeneradorViento: public ForceGenerator
{
public:
	GeneradorViento(Vector3 p, Vector3 v,Vector3 f):ForceGenerator(p,v),viento(f),k1(u) {

	}

	Vector3 fuerzaViento(Particle* p){
		return k1 * (viento - p->getVel());
	}

	Vector3 fuerzaViento(SolidoRigido* p) {
		return k1 * (viento - p->getLinearVel());
	}

	Vector3 setForce(Particle* p, double t);
	Vector3 setForce(SolidoRigido* p, double t);

private:

	Vector3 viento;
	float k1;
};

