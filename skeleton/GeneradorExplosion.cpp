#include "GeneradorExplosion.h"

Vector3 GeneradorExplosion::setForce(Particle* p, double t)
{
	tiempototal += t;
	if (tiempoinicial <= tiempototal) {
		if (tiempototal - tiempoinicial >= 25.0)tiempototal = 0;
		return fuerzaExplosion(p);
	}
	else {
		return Vector3(0, 0, 0);
	}	
}
