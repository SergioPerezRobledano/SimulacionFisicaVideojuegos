#pragma once
#include"GeneradorMuelleAnclado.h"
class GeneradorMuelle:public GeneradorMuelleAnclado
{
public:
	GeneradorMuelle(double K, double Rlenght,SisParticulas* s):GeneradorMuelleAnclado(K,Rlenght),sis(s) {}


private:
	SisParticulas* sis;
};

