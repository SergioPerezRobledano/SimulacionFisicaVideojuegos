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

	void update(double t);

private:
	vector<ForceGenerator*>generadores;
	SisParticulas* sisparticulas;
};

