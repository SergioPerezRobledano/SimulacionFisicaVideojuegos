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
	};
	SolidoRigido(PxTransform pos,PxScene* sc, Vector3 v,float inercia) :Initpos(pos), gScene(sc), vel(v) {
		shape = CreateShape(PxBoxGeometry(1, 1, 1));
		solidoR = gScene->getPhysics().createRigidDynamic(Initpos);
		solidoR->setLinearVelocity(v);
		solidoR->setAngularVelocity(Vector3(0));
		solidoR->attachShape(*shape);
		gScene->addActor(*solidoR);
		PxRigidBodyExt::updateMassAndInertia(*solidoR, inercia);
		renderItem = new RenderItem(shape, solidoR, { 1,0,0,1 });

	};
	void setForce(Vector3 f) {
		solidoR->setLinearVelocity(Vector3(0, 10, 0));
	}
private:
	PxShape* shape;
	RenderItem* renderItem;

	PxRigidDynamic* solidoR;
	PxScene* gScene;

	Vector3 vel;
	PxTransform Initpos;
};

