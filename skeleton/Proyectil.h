#pragma once
#include "Particle.h"

const double gr=9.8;

class Proyectil
{
public:
	Proyectil(double vel, double masa) :MasaR(masa), velR(vel){
		velS = 5.0;
		ajusteMasa();
		ajusteGravedad();
	};

	void ajusteMasa() {
		MasaS = MasaR * (pow(velR, 2) / pow(velS, 2));
	}

	void ajusteGravedad() {
		gS = pow(velS, 2) * gr/ velR;
	}

private:
	
	double MasaR;
	double MasaS;
	double velS;
	double velR;
	double gS;

};

