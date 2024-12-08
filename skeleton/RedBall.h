#pragma once
#include"SolidoRigido.h"
class RedBall:public SolidoRigido
{
public:
	RedBall(PxTransform pos, PxScene* sc, Vector3 v, float inercia) :SolidoRigido(pos, sc, v, inercia) {
		actualpos = pos.p;
		trayectoria = Vector3(-5,0,0);
		maxTiros = 3;
		tirar = true;
		solidoR = getSolido();
	};
	
	void shot() {
		actualpos = solidoR->getGlobalPose().p;
		solidoR->setLinearVelocity(actualpos-(actualpos-trayectoria));
	}

private:
	PxRigidDynamic* solidoR;
	Vector3 actualpos;
	Vector3 trayectoria;
	int maxTiros;
	bool tirar;
};

