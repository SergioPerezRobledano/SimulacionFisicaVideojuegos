#include "RenderUtils.hpp"
using namespace physx;
const double VIDA = 3.0;
class Particle
{
public:
	Particle(Vector3 pos, Vector3 Vel, Vector3 a,double d,float m)  {
		masa = m;
		fuerzaTotal = Vector3(0,0,0);
		ac = Vector3(0,0,0);
		dumping = d;
		vel = Vel;
		pose = PxTransform(pos);
		physx::PxVec4 col(1, 1, 1, 0.2);
		renderItem = new RenderItem(CreateShape(PxSphereGeometry(0.25)), &pose, col);
		vida = 3.0;

	};
	Particle(Vector3 pos, Vector3 Vel, Vector3 a, double d, float m,PxShape* cube, PxVec4 col) {
		masa = m;
		fuerzaTotal = Vector3(0, 0, 0);
		ac = Vector3(0, 0, 0);
		dumping = d;
		vel = Vel;
		pose = PxTransform(pos);
		renderItem = new RenderItem(cube, &pose, col);
		vida = 3.0;
	};
	~Particle() {
		renderItem->release();
		renderItem = nullptr;
	};

	void integrate(double t);

	void addForce(Vector3 a) {
		fuerzaTotal = a;
	};

	void calculateAceleration() {
		ac = fuerzaTotal / masa;
	}

	Vector3 getVel() { return vel; }

	double tiempo() { return tvida; }

	void settiempo(double t) { tvida=t+vida; }

	void setVida(double t) { vida = t; }

	Vector3 getPos() { return pose.p; }

private:
	double tvida;
	double vida;
	double dumping;

	float masa;

	Vector3 vel;
	Vector3 ac;
	Vector3 fuerzaTotal;

	physx::PxTransform pose;
	RenderItem* renderItem;

};

