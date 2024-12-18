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
	void addGeneratorG(ForceGenerator* g) {
		generadores.push_back(g);
		gravedad = g;
	}
	void addGeneratorM(ForceGenerator* g) {
		mAnclado=g;
	}

	void Clear() {
		generadores.clear();
		viento = nullptr;
		gravedad = nullptr;
		mAnclado = nullptr;
	}

	void update(double t);
	void updatesolidos(double t);
	void updateMuelles(double t);

private:
	vector<ForceGenerator*>generadores;
	ForceGenerator* viento;
	ForceGenerator* gravedad;
	ForceGenerator* mAnclado;
	GeneradorMuelle* generadoresM;
	SisParticulas* sisparticulas;
	SisSolidos* sissolidos;
};

