#include "GeneradorTorbellino.h"

Vector3 GeneradorTorbellino::setForce(Particle* p)
{
	/*Vector3 dist = initPos - p->getPos();
	if (abs(dist.x) <= volumen.x && abs(dist.y) <= volumen.y && abs(dist.z) <= volumen.z) {
		return fuerzaTorbellino(p);
	}
	else {
		return Vector3(0, 0, 0);
	}*/
	return fuerzaTorbellino(p);
}