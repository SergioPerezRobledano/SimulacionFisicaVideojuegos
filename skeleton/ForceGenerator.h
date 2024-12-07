#pragma once
#include "RenderUtils.hpp"
#include"SisParticulas.h"
#include"SisSolidos.h"
#include<cmath>


class ForceGenerator
{
public:
	ForceGenerator(Vector3 p,Vector3 v):initPos(p),volumen(v){}
	ForceGenerator() { initPos = Vector3(0);volumen = Vector3(0); };

	virtual Vector3 setForce(Particle* p, double t) = 0;
	virtual Vector3 setForce(SolidoRigido* p, double t) = 0;

protected:
	Vector3 initPos;
	Vector3 volumen;

};

