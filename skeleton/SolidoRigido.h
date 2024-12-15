#pragma once
#include "RenderUtils.hpp"
using namespace physx;

class SolidoRigido
{
public:

	SolidoRigido(PxTransform pos, PxShape* s, PxScene* sc,Vector3 v,float inercia):Initpos(pos),shape(s), gScene(sc),vel(v){
		solidoR = gScene->getPhysics().createRigidDynamic(Initpos);
		solidoR->setLinearVelocity(v);
		solidoR->setAngularVelocity(Vector3(0));
		solidoR->attachShape(*shape);
		gScene->addActor(*solidoR);
		PxRigidBodyExt::updateMassAndInertia(*solidoR, inercia);
		renderItem = new RenderItem(shape, solidoR, {1,0,0,1});
		trayectoria = Vector3(-5, 0, 0);
		sforce = 10.0f;
	};

	SolidoRigido(PxTransform pos, PxShape* s, PxScene* sc, Vector3 v, float inercia, PxVec4 col) :Initpos(pos), shape(s), gScene(sc), vel(v) {
		solidoR = gScene->getPhysics().createRigidDynamic(Initpos);
		solidoR->setLinearVelocity(v);
		solidoR->setAngularVelocity(Vector3(0));
		solidoR->attachShape(*shape);
		gScene->addActor(*solidoR);
		PxRigidBodyExt::updateMassAndInertia(*solidoR, inercia);
		renderItem = new RenderItem(shape, solidoR, col);
		trayectoria = Vector3(-5, 0, 0);
		sforce = 10.0f;
	};

	SolidoRigido(PxTransform pos,PxScene* sc, Vector3 v,float inercia) :Initpos(pos), gScene(sc), vel(v) {
		shape = CreateShape(PxSphereGeometry(2));
		solidoR = gScene->getPhysics().createRigidDynamic(Initpos);
		solidoR->setLinearVelocity(v);
		solidoR->setAngularVelocity(Vector3(0));
		solidoR->attachShape(*shape);
		gScene->addActor(*solidoR);
		PxRigidBodyExt::updateMassAndInertia(*solidoR, inercia);
		renderItem = new RenderItem(shape, solidoR, { 1,0,0,1 });
		trayectoria = Vector3(-5, 0, 0);
		sforce = 10.0f;

	};

	~SolidoRigido() {
		solidoR->release();
		solidoR=nullptr;
	}

	void setPos(Vector3 v) {
		solidoR->setGlobalPose(PxTransform(v));
	}

	void setForce(Vector3 f) {
		solidoR->addForce(f);
	}
	
	void setVel(Vector3 v) {
		solidoR->setLinearVelocity(v);
	}

	Vector3 getPos() {
		return solidoR->getGlobalPose().p;
	}

	Vector3 getInitPos() {
		return Initpos.p;
	}

	Vector3 getVel() {
		Vector3 aux = (solidoR->getGlobalPose().p - (solidoR->getGlobalPose().p + trayectoria));
		aux.normalize();
		return aux*sforce;
	}

	void Shoot() {
		Vector3 aux = (solidoR->getGlobalPose().p - (solidoR->getGlobalPose().p + trayectoria));
		aux.normalize();
		solidoR->setLinearVelocity(aux*sforce);
	}

	void changeT(char k) {
		switch (k)
		{
		case 'U': {
			trayectoria.y-=0.05;
			break;
		}
		case 'N':
		{
			trayectoria.y+= 0.05;
			break;
		}
		case 'H':
		{
			sforce+=0.5;
			break;

		}
		case 'J':
		{
			sforce-=0.5;
			break;
		}
		default:
			break;
		}
	}
	PxRigidDynamic* getSolido() {
		return solidoR;
	}

private:

	PxShape* shape;
	RenderItem* renderItem;

	PxRigidDynamic* solidoR;
	PxScene* gScene;

	Vector3 vel;
	Vector3 trayectoria;
	PxTransform Initpos;

	float sforce;

};

