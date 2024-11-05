#include "Particle.h"

void Particle::integrate(double t)
{
	sumatorioFuerzas();
	vel += fuerzaTotal * t;
	pose.p += vel*t;
	//0.998 elevado a t
	vel = vel * pow(dumping, t);
}
