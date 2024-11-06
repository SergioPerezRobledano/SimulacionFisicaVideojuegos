#include "Particle.h"

void Particle::integrate(double t)
{
	calculateAceleration();
	vel += ac * t;
	pose.p += vel*t;
	//0.998 elevado a t
	vel = vel * pow(dumping, t);
}
