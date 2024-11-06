#pragma once
#include "Particle.h"

const double gr=9.8;

class Proyectil
{
public:
	Proyectil(double vel, double masa, Vector3 pos,Vector3 ini) :MasaR(masa), velR(vel){
		velS = 5.0;
		ajusteMasa();
		ajusteGravedad();
		Vector3 dir = pos;
		dir.normalize();
		p = new Particle(ini, dir*velS, Vector3(0, -gS, 0), 0.998,4);
	};

	void ajusteMasa() {
		MasaS = MasaR * (pow(velR, 2) / pow(velS, 2));
	}

	void ajusteGravedad() {
		gS = pow(velS, 2) * gr/ pow(velR,2);
	}

	void Disparo(double t) {
		p->integrate(t);
	}

private:
	Particle* p;
	double MasaR;
	double MasaS;
	double velS;
	double velR;
	double gS;

};

