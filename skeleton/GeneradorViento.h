#pragma once
#include "SisParticulas.h"
#include <list>

const float u = 0.25;

class GeneradorViento
{
public:
	GeneradorViento(SisParticulas* p,Vector3 f):particulas(p),viento(f),rozamiento(u) {

	}
	Vector3 fuerzaViento(Particle* p){
		return rozamiento * (viento - p->getVel());
	}
	void setForce();
private:
	Vector3 viento;
	SisParticulas* particulas;
	float rozamiento;
};

