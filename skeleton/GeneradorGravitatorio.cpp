#include "GeneradorGravitatorio.h"

Vector3 GeneradorGravitatorio::setForce(Particle* p, double t)
{
	Vector3 dist = initPos - p->getPos();
	if (abs(dist.x) <= volumen.x && abs(dist.y) <= volumen.y && abs(dist.z) <= volumen.z) {
		return gravedad;
	}
	else {
		return Vector3(0, 0, 0);
	}
}
