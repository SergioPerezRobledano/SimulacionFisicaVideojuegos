#pragma once
#include "GeneradorSolidoRigido.h"
#include "ForceGenerator.h"
#include "SisFuerzas.h"
#include"GeneradorViento.h"
#include"GeneradorGravitatorio.h"
#include"GeneradorExplosion.h"
#include"GeneradorMuelleAnclado.h"
#include "RenderUtils.hpp"


//#include "Generador.h"
#include "Cesto.h"
#include <iostream>
using namespace physx;
class GameManager
{
public:
	GameManager(SolidoRigido* p,Cesto* c,PxScene* s, PxPhysics* px,SisFuerzas* f,SisParticulas* pa,SisSolidos* so,Generador* t):player(p),cesto(c),gScene(s),gPhysics(px),sFuerzas(f),sParticulas(pa),sSolidos(so),trayectoria(t) {
		currentLevel = 0;
	};
	void setUpLevel() {
		SolidoRigido* aux;
		switch (currentLevel) {
		case 0:
			sFuerzas->addGeneratorG(new GeneradorGravitatorio(Vector3(0, 0, 0), Vector3(100, 100, 100)));
			sSolidos->paredLevel1();
			for (auto s : sSolidos->getMSolidos()) {
				obstaculosM.push_back(s);
			}
			break;
		case 1:
			Level2();

			break;
		case 2:
			sFuerzas->addGeneratorG(new GeneradorGravitatorio(Vector3(0, 0, 0), Vector3(100, 100, 100)));
			sSolidos->muelleLevel3();
			sFuerzas->addGeneratorM(new GeneradorMuelleAnclado(1, 5));
			for (auto s : sSolidos->getMSolidos()) {
				obstaculosM.push_back(s);
			}
			break;
		default:
			sParticulas->addGenerator(new Generador(Vector3(0), FIN, player, 0.005));
			//sFuerzas->addGenerator(new GeneradorExplosion(Vector3(0, 0, 0), Vector3(100, 100, 100), 100.0));

			break;
		}
	}
	void Level2() {
		sFuerzas->addGeneratorG(new GeneradorGravitatorio(Vector3(0, 0, 0), Vector3(100, 100, 100)));
		PxRigidStatic* suelo = gPhysics->createRigidStatic(PxTransform(Vector3(-22, 2, 0)));
		PxRigidStatic* suelo1 = gPhysics->createRigidStatic(PxTransform(Vector3(0, 16, 0)));

		auto materialsinrebote = gPhysics->createMaterial(0.0f, 0.0f, 0.0f);
		PxShape* shape = CreateShape(PxBoxGeometry(3, 12, 1));
		PxShape* shape1 = CreateShape(PxBoxGeometry(25, 3, 1));

		suelo->attachShape(*shape);
		suelo1->attachShape(*shape1);

		gScene->addActor(*suelo);
		gScene->addActor(*suelo1);

		obstaculosInm.push_back({ suelo,new RenderItem(shape, suelo, { 0.25,1,0.5,1 }) });
		obstaculosInm.push_back({ suelo1,new RenderItem(shape1, suelo1, { 0.25,1,0.5,1 }) });

		sParticulas->addGeneratorV(new Generador(Vector3(0), NORMAL, player, 0.005));
		sFuerzas->addGeneratorV(new GeneradorViento(Vector3(0, 40, 0), Vector3(1000, 20, 100), Vector3(20, 0, 0)));
	}
	void Update(double t) {
		if (cesto->estaDentro(player->getPos())) {
			disparar = true;
			currentLevel++;
			clearLevel();
			setUpLevel();
			trayectoria->parar(true);
		}
	}
	void clearLevel() {

		player->setPos(player->getInitPos());
		player->setVel(Vector3(0));
		player->ResetTrayectoria();

		for (auto s : obstaculosInm) {
			DeregisterRenderItem(s.second);
			s.first->release();
		}
		obstaculosInm.clear();

		sSolidos->Clear();
		obstaculosM.clear();

		sParticulas->resetLevel();
		sFuerzas->Clear();
	}
	int getLevel() {
		return currentLevel;
	}

	void seyDisp(bool t) {
		disparar = t;
	}
	bool disparar = true;
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
	Generador* trayectoria;
	int currentLevel;

};

