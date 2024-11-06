#pragma once
#include "RenderUtils.hpp"
#include"SisParticulas.h"
#include<cmath>


class ForceGenerator
{
public:
	ForceGenerator(Vector3 p,Vector3 v):initPos(p),volumen(v){}

	virtual Vector3 setForce(Particle* p) = 0;

protected:
	Vector3 initPos;
	Vector3 volumen;

};

