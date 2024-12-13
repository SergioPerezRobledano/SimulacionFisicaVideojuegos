#pragma once
#include <vector>
#include "RenderUtils.hpp"
#include"ForceGenerator.h"
#include"GeneradorMuelle.h"

using namespace std;

class SisFuerzas
{

public:

	SisFuerzas(SisParticulas* p,SisSolidos* s) :sisparticulas(p),sissolidos(s){};

	void addGenerator(ForceGenerator* g) {
		generadores.push_back(g);
	}
	void addGeneratorM(GeneradorMuelle* g) {
		generadoresM=g;
	}

	void update(double t);
	void updatesolidos(double t);
	void updateMuelles(double t);

private:
	vector<ForceGenerator*>generadores;
	GeneradorMuelle* generadoresM;
	SisParticulas* sisparticulas;
	SisSolidos* sissolidos;
};

