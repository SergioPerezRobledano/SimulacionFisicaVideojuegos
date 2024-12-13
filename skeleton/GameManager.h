#pragma once
#include "GeneradorSolidoRigido.h"
#include "ForceGenerator.h"
#include "SisFuerzas.h"
#include"GeneradorViento.h"

//#include "Generador.h"
#include "Cesto.h"
#include <iostream>
using namespace physx;
class GameManager
{
public:
	GameManager(SolidoRigido* p,Cesto* c,PxScene* s, PxPhysics* px,SisFuerzas* f,SisParticulas* pa):player(p),cesto(c),gScene(s),gPhysics(px),sFuerzas(f),sParticulas(pa) {
		currentLevel = 0;
	};
	void setUpLevel(int l) {
		SolidoRigido* aux;
		switch (l) {
		case 0:
			aux = new SolidoRigido(PxTransform(Vector3(20, -4, 0)), CreateShape(PxBoxGeometry(8, 15, 2), gPhysics->createMaterial(0.0f, 0.0f, 0.0f)), gScene, Vector3(0), 1.0f, { 0.25,1,0.5,1 });
			//aux->getSolido()->setRigidDynamicLockFlag(PxRigidDynamicLockFlag::eLOCK_LINEAR_Y, true);
			obstaculosM.push_back(aux);
			sFuerzas->addGenerator(new GeneradorViento(Vector3(0, 40, 0), Vector3(100, 20, 100), Vector3(40, 0, 0)));
			sParticulas->addGenerator(new Generador(Vector3(0), NORMAL, player, 0.005));

			break;
		case 1:
			for (size_t i = 0; i < 10; i++)
			{
				obstaculosM.push_back(new SolidoRigido(PxTransform(Vector3(20, (-5 + 4 * i), 0)), CreateShape(PxBoxGeometry(2, 2, 2), gPhysics->createMaterial(0.0f, 0.0f, 0.0f)), gScene, Vector3(0), 1.0f, { 0.25,1,0.5,1 }));
			}
			break;
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
	SisParticulas* sParticulas;
	SisFuerzas* sFuerzas;
	PxScene* gScene;
	PxPhysics* gPhysics;
	int currentLevel;
};

