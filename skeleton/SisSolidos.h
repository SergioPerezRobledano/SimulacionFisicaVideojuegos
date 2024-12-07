#pragma once
#include"GeneradorSolidoRigido.h"
using namespace std;
class SisSolidos
{
public:
	SisSolidos() {};
	void addGeneratorS(GeneradorSolidoRigido* g) {
		gsolidos.push_back(g);
	}
	void addSolido(SolidoRigido* s) {
		solidos.push_back(s);
	}
	void uploadSolidos() {
		for (auto g:gsolidos)
		{
			list<SolidoRigido*> s=g->getS();
			for (auto r : s) {
				solidos.push_back(r);
			}
		}
	}
	void Generate() {
		for (auto g : gsolidos) {
			g->Generate();
		}
	}
	std::list<SolidoRigido*> getSolidos() {
		return solidos;
	}
private:
	std::list<GeneradorSolidoRigido*>gsolidos;
	std::list<SolidoRigido*>solidos;
};

