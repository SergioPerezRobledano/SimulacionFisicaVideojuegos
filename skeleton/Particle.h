#include "RenderUtils.hpp"
using namespace physx;
const double VIDA = 3.0;
class Particle
{
public:
	Particle(Vector3 pos, Vector3 Vel, Vector3 a,double d)  {
		ac = a;
		dumping = d;
		vel = Vel;
		pose = PxTransform(pos);
		physx::PxVec4 col(1, 1, 1, 1);
		renderItem = new RenderItem(CreateShape(PxSphereGeometry(1)), &pose, col);
	};
	~Particle() {
		renderItem = nullptr;
	};

	void integrate(double t);

	void setACeleration(Vector3 a) {
		ac = a;
	};

	Vector3 getVel() { return vel; }

	double tiempo() { return tvida; }

	void settiempo(double t) { tvida=t+VIDA; }


	Vector3 getPos() { return pose.p; }

private:
	double tvida;
	double dumping;
	Vector3 vel;
	Vector3 ac;
	physx::PxTransform pose;
	RenderItem* renderItem;

};

