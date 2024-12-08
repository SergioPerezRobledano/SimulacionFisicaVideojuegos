#include <ctype.h>

#include <PxPhysicsAPI.h>
#include <iostream>
#include <vector>
#include "Vector3DSIM.h"
#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include"SisFuerzas.h"
#include"GeneradorGravitatorio.h"
#include"GeneradorViento.h"
#include "GeneradorTorbellino.h"
#include "GeneradorExplosion.h"
#include "GeneradorMuelleAnclado.h"
#include "GeneradorMuelle.h"
#include "GeneradorFlotacion.h"
#include "GeneradorSolidoRigido.h"



#include <iostream>

std::string display_text = "This is a test";


using namespace physx;

PxDefaultAllocator		gAllocator;
PxDefaultErrorCallback	gErrorCallback;

PxFoundation*			gFoundation = NULL;
PxPhysics*				gPhysics	= NULL;


PxMaterial*				gMaterial	= NULL;

PxPvd*                  gPvd        = NULL;

PxDefaultCpuDispatcher*	gDispatcher = NULL;
PxScene*				gScene      = NULL;
ContactReportCallback gContactReportCallback;

Vector3DSIM* ejex = new Vector3DSIM(1.0, 0.0, 0.0);
Vector3DSIM* ejey = new Vector3DSIM(0.0, 1.0, 0.0);
Vector3DSIM* ejez = new Vector3DSIM(0.0, 0.0, 1.0);

Vector3 pos = { 0,0,0 };
physx::PxTransform* posx = new PxTransform({ 10,0,0 });
physx::PxTransform* posy = new PxTransform({ 0,10,0 });
physx::PxTransform* posz = new PxTransform({ 0,0,10 });

physx::PxVec4 col(1,1,1,1);
physx::PxVec4 colx(1,0,0,1);
physx::PxVec4 coly(0,1,0,1);
physx::PxVec4 colz(0,0,1,1);

Vector3 vel(1, 0, 0);

physx::PxShape* s;

SisParticulas* sistema=new SisParticulas();
SisFuerzas* fuerzas=new SisFuerzas(sistema);
GeneradorSolidoRigido* solidGenerator;

//Particle* p ;
//vector<Proyectil*>canon;





// Initialize physics engine
void initPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	gFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, gAllocator, gErrorCallback);

	gPvd = PxCreatePvd(*gFoundation);
	PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate(PVD_HOST, 5425, 10);
	gPvd->connect(*transport,PxPvdInstrumentationFlag::eALL);

	gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(),true,gPvd);

	gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);

	s = CreateShape(PxSphereGeometry(2));

	sistema->addGenerator(Vector3(0, 0, 0), NORMAL);

	//Fuerzas

	//fuerzas->addGenerator(new GeneradorGravitatorio(Vector3(0, 0, 0), Vector3(100, 100, 100)));
	//fuerzas->addGenerator(new GeneradorViento(Vector3(0, 40, 0), Vector3(100, 20, 100), Vector3(40, 0, 0)));
	//fuerzas->addGenerator(new GeneradorTorbellino(Vector3(0, 40, 0), Vector3(200, 100, 200)));
	//fuerzas->addGenerator(new GeneradorExplosion(Vector3(0, 0, 0), Vector3(100, 100, 100),100.0));
	
	//Muelles
	
	//sistema->muelleDemo();
	//sistema->muelleParticulasDemo();
	
	//fuerzas->addGenerator(new GeneradorMuelleAnclado(1, 20));
	//fuerzas->addGeneratorM(new GeneradorMuelle(1, 5,sistema));
	//fuerzas->addGenerator(new GeneradorFlotacion(8, 10,2));

	 //p = new Particle(pos,vel,Vector3(0,1,0), 0.998);


	

	 //RenderItem* Sphere = new RenderItem(s, pos, col);
	 //
	 //RenderItem* x = new RenderItem(s, posx, colx);
	 //RenderItem* y = new RenderItem(s, posy, coly);
	 //RenderItem* z = new RenderItem(s, posz, colz);




	// For Solid Rigids +++++++++++++++++++++++++++++++++++++
	PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
	sceneDesc.gravity = PxVec3(0.0f, -9.8f, 0.0f);
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = contactReportFilterShader;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	gScene = gPhysics->createScene(sceneDesc);
	//Parte 2
	solidGenerator = new GeneradorSolidoRigido(Vector3(0), 1, gScene);
	PxRigidStatic* suelo = gPhysics->createRigidStatic(PxTransform(Vector3(0)));
	PxShape* shape = CreateShape(PxBoxGeometry(100, 0.1, 100));
	suelo->attachShape(*shape);
	gScene->addActor(*suelo);
	RenderItem* item;
	item = new RenderItem(shape, suelo, { 1,1,1,1 });
	}


// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);
	gScene->simulate(t);
	gScene->fetchResults(true);
	//sistema->Generate(t);
	//fuerzas->update(t);
	//fuerzas->updateMuelles(t);
	//sistema->Integrate(t);
	solidGenerator->Generate();


	//for (auto e : canon)e->Disparo(t);
	//p->integrate(t);
}

// Function to clean data
// Add custom code to the begining of the function
void cleanupPhysics(bool interactive)
{
	PX_UNUSED(interactive);
	
	// Rigid Body ++++++++++++++++++++++++++++++++++++++++++
	gScene->release();
	gDispatcher->release();
	// -----------------------------------------------------
	gPhysics->release();	
	PxPvdTransport* transport = gPvd->getTransport();
	gPvd->release();
	transport->release();
	
	gFoundation->release();
	}

// Function called when a key is pressed
void keyPress(unsigned char key, const PxTransform& camera)
{
	PX_UNUSED(camera);

	switch(toupper(key))
	{
	case 'P': {
		solidGenerator->setForce(Vector3(0));

		//canon.push_back(new Proyectil(250.0,6,GetCamera()->getDir(),camera.p));
	}
	//case ' ': {
	//}
	case ' ':
	{
		break;
	}
	default:
		break;
	}
}

void onCollision(physx::PxActor* actor1, physx::PxActor* actor2)
{
	PX_UNUSED(actor1);
	PX_UNUSED(actor2);
}


int main(int, const char*const*)
{
#ifndef OFFLINE_EXECUTION 
	extern void renderLoop();
	renderLoop();
#else
	static const PxU32 frameCount = 100;
	initPhysics(false);
	for(PxU32 i=0; i<frameCount; i++)
		stepPhysics(false);
	cleanupPhysics(false);
#endif

	return 0;
}