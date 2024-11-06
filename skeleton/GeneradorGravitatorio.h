#pragma once
#include "ForceGenerator.h"


const float G=9.8;

using namespace physx;
using namespace std;

class GeneradorGravitatorio: public ForceGenerator
{
public:
	GeneradorGravitatorio(Vector3 p, Vector3 v) :ForceGenerator(p, v) {
		gravedad = Vector3(0.0, -G, 0.0);

	}
	Vector3 setForce(Particle* p);
private:
	Vector3 gravedad;

};

