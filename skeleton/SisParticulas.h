#pragma once
#include <vector>
#include "RenderUtils.hpp"
#include "Generador.h"


using namespace std;

class SisParticulas
{
public:
	SisParticulas() {
		//generador.push_back(new Generador(Vector3(0, 0, 0),GAUSS));
	}
	~SisParticulas() {
		for (auto e : generador) {
			delete e;
		}
	};

	void muelleDemo() {
		particulasMA.push_back( new Particle({ 0.0,0.0,0.0, }, { 0.0,0.0,0.0, }, { 0.0,0.0,0.0, }, 0.998, 1.0));
	}
	void muelleParticulasDemo() {
		particulasM.first=new Particle({ 20.0,0.0,0.0, }, { 0.0,0.0,0.0, }, { 0.0,0.0,0.0, }, 0.998, 1.0);
		particulasM.second=new Particle({ 20.0,10.0,0.0, }, { 0.0,0.0,0.0, }, { 0.0,0.0,0.0, }, 0.998, 1.0);
	}

	void addGenerator(Vector3 v,tipo t,SolidoRigido* b) {
		Levelgenerador.push_back(new Generador(v,t,b,0.0f));
	}

	void addGenerator(Generador*g) {
		generador.push_back(g);
	}

	void Generate(double t);
	void Integrate(double t);
	void update(double t);

	list<Particle*>getParticulas() {
		list<Particle*>l;
		for (auto g : generador) {
			for (auto p : g->getParticulas()) {
				l.push_back(p);
			}
		}
		for (auto s : Levelgenerador) {
			for (auto p : s->getParticulas()) {
				l.push_back(p);
			}
		}
		for (auto ma : particulasMA) {
			l.push_back(ma);
		}
		return l;
	}
	pair<Particle*, Particle*>getParticulasM() {
		return particulasM;
	}

	vector<Generador*> getGeneradores() { return generador; };
	void resetLevel() {
		for (auto p : Levelgenerador){
			delete p;
		}
		Levelgenerador.clear();
	}
private:
	Particle* muelle=nullptr;
	vector<Generador*>generador;
	vector<Generador*>Levelgenerador;
	pair<Particle*, Particle*>particulasM;
	list<Particle*>particulasMA;
};

