#include "GeneradorViento.h"

Vector3 GeneradorViento::setForce(Particle* p, double t)
{
	Vector3 dist = initPos - p->getPos();
	if (abs(dist.x) <= volumen.x && abs(dist.y) <= volumen.y && abs(dist.z) <= volumen.z) {
		return fuerzaViento(p);
	}
	else {
		return Vector3(0, 0, 0);
	}
}

Vector3 GeneradorViento::setForce(SolidoRigido* p, double t)
{
	Vector3 dist = initPos - p->getPos();
	if (abs(dist.x) <= volumen.x && abs(dist.y) <= volumen.y && abs(dist.z) <= volumen.z) {
		return fuerzaViento(p);
	}
	else {
		return Vector3(0, 0, 0);
	}
}
