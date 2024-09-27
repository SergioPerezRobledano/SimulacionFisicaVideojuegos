#include "RenderUtils.hpp"
using namespace physx;

class Particle
{
public:
	Particle(Vector3 pos, Vector3 Vel, physx::PxShape* s)  {
		vel = Vel;
		pose = PxTransform(pos);
		physx::PxVec4 col(1, 1, 1, 1);
		renderItem = new RenderItem(s, &pose, col);
	};
	~Particle() {
		renderItem = nullptr;
		delete renderItem;
	};

	void integrate(double t);
private:
	Vector3 vel;
	physx::PxTransform pose;
	RenderItem* renderItem;

};

