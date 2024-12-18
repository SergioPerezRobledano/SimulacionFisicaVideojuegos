#pragma once
#include "RenderUtils.hpp"
#include<list>
using namespace physx;
class Cesto
{
public:
	Cesto(Vector3 v,Vector3 pos, PxVec4 col, PxScene* gScene, PxPhysics* gPhysics):volumen(v),initPos(pos) {
		PxRigidStatic* suelo = gPhysics->createRigidStatic(PxTransform(Vector3(pos.x, pos.y-v.y, 0)));
		PxRigidStatic* suelo1 = gPhysics->createRigidStatic(PxTransform(Vector3(pos.x-v.x, pos.y-0.5, 0)));
		PxRigidStatic* suelo2 = gPhysics->createRigidStatic(PxTransform(Vector3(pos.x + v.x, pos.y-0.5, 0)));
		auto materialsinrebote = gPhysics->createMaterial(0.0f, 0.0f, 0.0f);
		PxShape* shape = CreateShape(PxBoxGeometry(v.x, 1, 1), materialsinrebote);
		PxShape* shape1 = CreateShape(PxBoxGeometry(1, v.y, 1));
		PxShape* shape2 = CreateShape(PxBoxGeometry(1, v.y, 1));
		suelo->attachShape(*shape);
		suelo1->attachShape(*shape1);
		suelo2->attachShape(*shape2);
		gScene->addActor(*suelo);
		gScene->addActor(*suelo1);
		gScene->addActor(*suelo2);
		cesto.push_back({ suelo,new RenderItem(shape, suelo, col) });
		cesto.push_back({ suelo1,new RenderItem(shape1, suelo1, col) });
		cesto.push_back({ suelo2,new RenderItem(shape2, suelo2, col) });
	};
	~Cesto() {
		for (auto s : cesto) {
			DeregisterRenderItem(s.second);
			s.first->release();
		}
		cesto.clear();
	}
	Vector3 getVolumen() {
		return volumen;
	}
	Vector3 getPos() {
		return initPos;
	}
	bool estaDentro(Vector3 b) {
		return (b.x > initPos.x - volumen.x && b.x < initPos.x + volumen.x) && (b.y > initPos.y - volumen.y && b.y < initPos.y + volumen.y);
	}
private:
	std::list<std::pair<PxRigidStatic*,RenderItem*>>cesto;
	Vector3 volumen;
	Vector3 initPos;
};

