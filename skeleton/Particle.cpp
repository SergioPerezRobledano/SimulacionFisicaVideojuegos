#include "Particle.h"

void Particle::integrate(double t)
{
	vel += ac * t;
	pose.p += vel*t;

}
