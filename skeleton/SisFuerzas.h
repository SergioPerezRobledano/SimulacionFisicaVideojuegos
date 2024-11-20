#pragma once
#include <vector>
#include "RenderUtils.hpp"
#include"ForceGenerator.h"

using namespace std;

class SisFuerzas
{

public:

	SisFuerzas(SisParticulas* p) :sisparticulas(p){};

	void addGenerator(ForceGenerator* g) {
		generadores.push_back(g);
	}
	void addGeneratorM(ForceGenerator* g) {
		generadoresM=g;
	}

	void update(double t);
	void updateMuelles(double t);

private:
	vector<ForceGenerator*>generadores;
	ForceGenerator* generadoresM;
	SisParticulas* sisparticulas;
};

