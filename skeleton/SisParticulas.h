#pragma once
#include <vector>
#include "RenderUtils.hpp"
#include "Generador.h"

using namespace std;

class SisParticulas
{
public:
	SisParticulas() {
		generador.push_back(new Generador(Vector3(0, 0, 0),GAUSS));
	}
	~SisParticulas() {
		for (auto e : generador) {
			delete e;
		}
	};

	void addGenerator(Vector3 v,tipo t) {
		generador.push_back(new Generador(v,t));
	}

	void update(double t);

	vector<Generador*> getParticulas() { return generador; };

private:
	vector<Generador*>generador;
};

