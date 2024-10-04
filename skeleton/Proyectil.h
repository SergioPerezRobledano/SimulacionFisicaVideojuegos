#pragma once
#include "Particle.h"

const double gr=9.8;

class Proyectil
{
public:
	Proyectil(double vel, double masa, Vector3 pos) :MasaR(masa), velR(vel){
		velS = 5.0;
		ajusteMasa();
		ajusteGravedad();
		Vector3 dir = Vector3(0, 0, 0) - pos;
		dir.normalize();
		p = new Particle(pos, dir*velS, Vector3(0, -gS, 0), 0.998);
	};

	void ajusteMasa() {
		MasaS = MasaR * (pow(velR, 2) / pow(velS, 2));
	}

	void ajusteGravedad() {
		gS = pow(velS, 2) * gr/ velR;
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

