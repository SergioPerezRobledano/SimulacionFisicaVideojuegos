#pragma once
#include "GeneradorSolidoRigido.h"
#include "ForceGenerator.h"
#include "SisFuerzas.h"
#include"GeneradorViento.h"
#include"GeneradorMuelleAnclado.h"

//#include "Generador.h"
#include "Cesto.h"
#include <iostream>
using namespace physx;
class GameManager
{
public:
	GameManager(SolidoRigido* p,Cesto* c,PxScene* s, PxPhysics* px,SisFuerzas* f,SisParticulas* pa,SisSolidos* so):player(p),cesto(c),gScene(s),gPhysics(px),sFuerzas(f),sParticulas(pa),sSolidos(so) {
		currentLevel = 2;
	};
	void setUpLevel() {
		SolidoRigido* aux;
		switch (currentLevel) {
		case 0:
			aux = new SolidoRigido(PxTransform(Vector3(20, -4, 0)), CreateShape(PxBoxGeometry(8, 15, 2), gPhysics->createMaterial(0.0f, 0.0f, 0.0f)), gScene, Vector3(0), 1.0f, { 0.25,1,0.5,1 });
			//aux->getSolido()->setRigidDynamicLockFlag(PxRigidDynamicLockFlag::eLOCK_LINEAR_Y, true);
			obstaculosM.push_back(aux);


			break;
		case 1:
			sol();

			break;
		case 2:
			sSolidos->muelleDemo();
			sFuerzas->addGeneratorM(new GeneradorMuelleAnclado(1, 5));
			break;
		}
	}
	void sol() {
		PxRigidStatic* suelo = gPhysics->createRigidStatic(PxTransform(Vector3(-22, 2, 0)));
		PxRigidStatic* suelo1 = gPhysics->createRigidStatic(PxTransform(Vector3(0, 16, 0)));

		auto materialsinrebote = gPhysics->createMaterial(0.0f, 0.0f, 0.0f);
		PxShape* shape = CreateShape(PxBoxGeometry(3, 12, 1));
		PxShape* shape1 = CreateShape(PxBoxGeometry(25, 3, 1));

		suelo->attachShape(*shape);
		suelo1->attachShape(*shape1);

		gScene->addActor(*suelo);
		gScene->addActor(*suelo1);

		RenderItem* item;
		item = new RenderItem(shape, suelo, { 0.25,1,0.5,1 });
		RenderItem* item1;
		item = new RenderItem(shape1, suelo1, { 0.25,1,0.5,1 });

		obstaculosInm.push_back({ suelo,item });
		obstaculosInm.push_back({ suelo1,item1 });

		//sParticulas->addGeneratorV(new Generador(Vector3(0), NORMAL, player, 0.005));
		sFuerzas->addGeneratorV(new GeneradorViento(Vector3(0, 40, 0), Vector3(1000, 20, 100), Vector3(20, 0, 0)));
	}
	void Update(double t) {
		if (cesto->estaDentro(player->getPos())) {
			currentLevel++;
			clearLevel();
			setUpLevel();
		}
	}
	void clearLevel() {
		player->setPos(player->getInitPos());
		player->setVel(Vector3(0));
		for (auto s : obstaculosInm) {
			//s.second->release();
			gScene->removeActor(*s.first);
			//s.first->release();
			s.first = nullptr;
			s.second->release();
			//s.first->release();
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
	std::list<pair<PxRigidStatic*,RenderItem*>> obstaculosInm;
	std::list<SolidoRigido*> obstaculosM;
	SisParticulas* sParticulas;
	SisFuerzas* sFuerzas;
	SisSolidos* sSolidos;
	PxScene* gScene;
	PxPhysics* gPhysics;
	int currentLevel;
};

