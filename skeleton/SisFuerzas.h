#pragma once
#include <vector>
#include "RenderUtils.hpp"
#include"ForceGenerator.h"
#include"GeneradorMuelle.h"

using namespace std;

class SisFuerzas
{

public:

	SisFuerzas(SisParticulas* p, SisSolidos* s) :sisparticulas(p), sissolidos(s) { viento = nullptr; };

	void addGenerator(ForceGenerator* g) {
		generadores.push_back(g);
	}
	void addGeneratorV(ForceGenerator* g) {
		generadores.push_back(g);
		viento = g;
	}
	void addGeneratorM(ForceGenerator* g) {
		mAnclado=g;
	}

	void update(double t);
	void updatesolidos(double t);
	void updateMuelles(double t);

private:
	vector<ForceGenerator*>generadores;
	ForceGenerator* viento;
	ForceGenerator* mAnclado;
	GeneradorMuelle* generadoresM;
	SisParticulas* sisparticulas;
	SisSolidos* sissolidos;
};

