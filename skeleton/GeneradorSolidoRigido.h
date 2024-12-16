#pragma once
#include "RenderUtils.hpp"
#include"RedBall.h"
#include <random>
#include<list>
class GeneradorSolidoRigido
{
public:
	GeneradorSolidoRigido(Vector3 pos,int max, PxScene* sc):ipos(pos),maxSolid(max),gScene(sc){}

	void Generate() {
		if (listaSolidos.size() < maxSolid) {
			//auto aux = new SolidoRigido(PxTransform(Vector3(0, Random(0, 100), 0)), gScene, Vector3(0, -10, 0),Random(0.0,100));
			auto aux = new SolidoRigido(PxTransform(Vector3(-30,0, 0)), CreateShape(PxSphereGeometry(2)), gScene, Vector3(0, 0, 0),1);
			listaSolidos.push_back(aux);
		}
	}
	float Random(float min, float max) {
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_real_distribution<float>distrib(min, max);
		return distrib(gen);
	}
	void setForce(Vector3 f) {
		for (auto s : listaSolidos) {
			s->setForce(Vector3(0));
		}
	}

	std::list <SolidoRigido*> getS();

private:
	Vector3 ipos;
	int maxSolid;
	std::list<SolidoRigido*>listaSolidos;
	PxScene* gScene;
};

