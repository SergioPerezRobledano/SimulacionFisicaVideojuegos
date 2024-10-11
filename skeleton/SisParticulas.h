#pragma once
#include <vector>
#include "RenderUtils.hpp"
#include "Generador.h"

using namespace std;

class SisParticulas
{
public:
	SisParticulas() {
		generador.push_back(new Generador(Vector3(0, 0, 0)));
	}
	//~SisParticulas();

	void update(double t);
private:
	vector<Generador*>generador;
};

