#pragma once
#include "RenderUtils.hpp"
#include"SolidoRigido.h"
#include <random>
#include<list>
class GeneradorSolidoRigido
{
public:
	GeneradorSolidoRigido(Vector3 pos,int max, PxScene* sc):ipos(pos),maxSolid(max),gScene(sc){}

	void Generate() {
		if (listaSolidos.size() < maxSolid) {
			auto aux = new SolidoRigido(PxTransform(Vector3(0, Random(0, 100), 0)), gScene, Vector3(0, -10, 0),Random(0.0,100));
			listaSolidos.push_back(aux);
		}
	}
	float Random(float min, float max) {
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_real_distribution<float>distrib(min, max);
		return distrib(gen);
	}

private:
	Vector3 ipos;
	int maxSolid;
	std::list<SolidoRigido*>listaSolidos;
	PxScene* gScene;
};

