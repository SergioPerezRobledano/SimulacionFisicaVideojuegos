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


			break;
		case 1:
			PxRigidStatic * suelo = gPhysics->createRigidStatic(PxTransform(Vector3(-30,0, 0)));
			PxRigidStatic* suelo1 = gPhysics->createRigidStatic(PxTransform(Vector3(0,20, 0)));

			auto materialsinrebote = gPhysics->createMaterial(0.0f, 0.0f, 0.0f);
			PxShape* shape = CreateShape(PxBoxGeometry(5, 20, 1));
			PxShape* shape1 = CreateShape(PxBoxGeometry(40, 5, 1), materialsinrebote);

			suelo->attachShape(*shape);
			suelo1->attachShape(*shape1);

			gScene->addActor(*suelo);
			gScene->addActor(*suelo1);

			RenderItem* item;
			item = new RenderItem(shape, suelo, col);
			RenderItem* item1;
			item = new RenderItem(shape1, suelo1, col);
			RenderItem* item2;
			item = new RenderItem(shape2, suelo2, col);
			sFuerzas->addGenerator(new GeneradorViento(Vector3(0, 40, 0), Vector3(100, 20, 100), Vector3(40, 0, 0)));
			sParticulas->addGenerator(new Generador(Vector3(0), NORMAL, player, 0.005));
			break;
		}
	}
	void Update(double t) {
		if (cesto->estaDentro(player->getPos())) {
			currentLevel++;
			clearLevel();
			setUpLevel(currentLevel);
		}
	}
	void clearLevel() {
		player->setPos(player->getInitPos());
		player->setVel(Vector3(0));
		for (auto s : obstaculosInm) {
			s->release();
		}
		obstaculosInm.clear();
		for (auto s : obstaculosM)
		{
			delete s;
		}
		obstaculosM.clear();

		sParticulas->resetLevel();
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

