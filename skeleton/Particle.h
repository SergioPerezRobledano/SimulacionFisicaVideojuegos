#include "RenderUtils.hpp"
using namespace physx;

class Particle
{
public:
	Particle(Vector3 pos, Vector3 Vel, physx::PxShape* s,double d)  {
		dumping = d;
		vel = Vel;
		ac = Vector3(0, 0, 0);
		pose = PxTransform(pos);
		physx::PxVec4 col(1, 1, 1, 1);
		renderItem = new RenderItem(s, &pose, col);
	};
	~Particle() {
		renderItem = nullptr;
		delete renderItem;
	};

	void integrate(double t);

	void setACeleration(Vector3 a) {
		ac = a;
	};

	Vector3 getVel() { return vel; }

private:
	double dumping;
	Vector3 vel;
	Vector3 ac;
	physx::PxTransform pose;
	RenderItem* renderItem;

};

