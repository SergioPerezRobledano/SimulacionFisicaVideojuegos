#pragma once
#include"GeneradorSolidoRigido.h"
using namespace std;
class SisSolidos
{
public:
	SisSolidos(PxScene* sc,PxPhysics* px):gScene(sc),gPhysics(px) {};
	void addGeneratorS(GeneradorSolidoRigido* g) {
		gsolidos.push_back(g);
	}
	void addSolido(SolidoRigido* s) {
		solidos.push_back(s);
	}
	void addPlayer(SolidoRigido* s) {
		player = s;
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
	void muelleLevel3() {
		msolidos.push_back(new SolidoRigido(PxTransform(Vector3(0, 0, 0)), CreateShape(PxBoxGeometry(3,3,3)), gScene, Vector3(0, 0, 0), 1));
	}
	void paredLevel1() {
		solidos.push_back(new SolidoRigido(PxTransform(Vector3(20, -4, 0)), CreateShape(PxBoxGeometry(8, 15, 2), gPhysics->createMaterial(0.0f, 0.0f, 0.0f)), gScene, Vector3(0), 1.0f, { 0.25,1,0.5,1 }));
	}
	std::list<SolidoRigido*> getAllSolidos() {
		std::list<SolidoRigido*>l = solidos;
		l.push_back(player);
		return l;
	}

	std::list<SolidoRigido*> getSolidos() {
		return solidos;
	}

	std::list<SolidoRigido*> getMSolidos() {
		return msolidos;
	}

	SolidoRigido* getPlayer() {
		return player;
	}
	void Clear() {
		for (auto s : solidos) {
			delete s;
		}
		solidos.clear();
		for (auto s : msolidos) {
			delete s;
		}
		msolidos.clear();
	}
private:
	std::list<GeneradorSolidoRigido*>gsolidos;
	std::list<SolidoRigido*>solidos;
	std::list<SolidoRigido*>msolidos;
	SolidoRigido* player;
	PxScene* gScene;
	PxPhysics* gPhysics;
};

