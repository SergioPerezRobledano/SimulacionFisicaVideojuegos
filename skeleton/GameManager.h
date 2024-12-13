#pragma once
#include "GeneradorSolidoRigido.h"
#include "Cesto.h"
#include <iostream>
using namespace physx;
class GameManager
{
public:
	GameManager(SolidoRigido* p,Cesto* c,PxScene* s, PxPhysics* px):player(p),cesto(c),gScene(s),gPhysics(px) {
		currentLevel = 0;
	};
	void setUpLevel(int l) {
		switch (l) {
		case 0:
			for (size_t i = 0; i < 10; i++)
			{
				obstaculosM.push_back(new SolidoRigido(PxTransform(Vector3(20, (-5 + 4 * i), 0)), CreateShape(PxBoxGeometry(2, 2, 2), gPhysics->createMaterial(0.0f, 0.0f, -1.0f)), gScene, Vector3(0), 0.001f, {0.25,1,0.5,1}));
			}
		}
	}
	void Update(double t) {
		if (cesto->estaDentro(player->getPos())) {
			std::cout << "Dentro";
		}
	}
private:
	SolidoRigido* player;
	Cesto* cesto;
	std::list<PxRigidStatic*> obstaculosInm;
	std::list<SolidoRigido*> obstaculosM;
	PxScene* gScene;
	PxPhysics* gPhysics;
	int currentLevel;
};

