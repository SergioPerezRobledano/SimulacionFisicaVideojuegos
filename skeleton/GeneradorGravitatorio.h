#pragma once

#include "SisParticulas.h"
#include <list>

const float G=9.8;

using namespace physx;
using namespace std;

class GeneradorGravitatorio
{
public:
	GeneradorGravitatorio(SisParticulas* p) :gravedad(Vector3(0.0,-G,0.0)),particulas(p) {}
	void setForce();
private:
	Vector3 gravedad;
	SisParticulas* particulas;
};

