#pragma once
#include"ForceGenerator.h"
class GeneradorFlotacion : public ForceGenerator
{
public:
	GeneradorFlotacion(float H, float V, float D) :h(H),v(V),d(D){
		liquid = new Particle({ 0.0,10.0,0.0, }, { 0.0,0.0,0.0, }, { 0.0,0.0,0.0, }, 0.998, 1.0, CreateShape(PxBoxGeometry(10, 1, 10)), { 0,0,1,0 });
	};
	Vector3 fuerzaFlotacion(Particle* p) {
		float hp = p->getPos().y;
		float h0 = liquid->getPos().y;
		Vector3 f(0);
		float immersed = 0.0;
		if (hp - h0 > h * 0.5) {
			immersed = 0.0;
		}
		else if (h0 - hp > h * 0.5) {
			immersed = 1.0;
		}
		else {
			immersed = (h0 - hp) / h + 0.5;
		}
		f.y = d * v * immersed;
		return f;
	}
	Vector3 setForce(Particle* p, double t);
private:
	float h, v, d;
	Particle* liquid;
};

