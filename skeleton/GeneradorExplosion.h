#pragma once
#include "ForceGenerator.h"

const float k = 10000;

using namespace physx;
using namespace std;

class GeneradorExplosion : public ForceGenerator
{
public:
	GeneradorExplosion(Vector3 p, Vector3 v,float r) :ForceGenerator(p, v),radio(r) {
		intensity = k;
		tconst = 0.25;
		tiempoinicial = 1000;
		tiempototal = 0.0;
	}

	Vector3 setForce(Particle* p, double t);

	Vector3 fuerzaExplosion(Particle* p) {
		Vector3 aux = { p->getPos().x - initPos.x,p->getPos().y - initPos.y,p->getPos().z - initPos.z };
		dist = aux.magnitude();
		if (dist < radio) {
			return aux * (intensity / pow(dist, 2)) * PxExp(-(tiempoinicial - tiempoinicial) / tconst);
		}
		else {
			return Vector3(0, 0, 0);
		}
	}

private:
	float intensity;
	float radio;
	float dist;
	double tconst;
	double tiempototal;
	double tiempoinicial;
};

