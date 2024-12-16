#pragma once
#include"GeneradorSolidoRigido.h"
using namespace std;
class SisSolidos
{
public:
	SisSolidos(PxScene* sc):gScene(sc) {};
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
	void muelleDemo() {
		msolidos.push_back(new SolidoRigido(PxTransform(Vector3(0, 0, 0)), CreateShape(PxBoxGeometry(3,3,3)), gScene, Vector3(0, 0, 0), 1));
	}
	std::list<SolidoRigido*> getSolidos() {
		return solidos;
	}
	std::list<SolidoRigido*> getMSolidos() {
		return msolidos;
	}
private:
	std::list<GeneradorSolidoRigido*>gsolidos;
	std::list<SolidoRigido*>solidos;
	std::list<SolidoRigido*>msolidos;
	PxScene* gScene;
};

