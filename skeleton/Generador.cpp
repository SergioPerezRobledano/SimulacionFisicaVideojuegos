#include "Generador.h"
#include <random>
#include <iostream>

void Generador::Generate(double t)
{
	//std::cout << t;
	tiempototal += t;
	if (generar) {
		tiempogeneracion += t;
		Particle* aux;
		if (tiempogeneracion >= spawn) {
			if (distribucion == GAUSS) {
				aux = new Particle(iniPos, Vector3(generateGausssian(0.0, 2), generateGausssian(20, 2), generateGausssian(0, 2)), Vector3(0, 0, 0), 0.998, 1.0);

			}
			else {
				if (distribucion == NORMAL) {
					aux = new Particle(Vector3(-40, generateUniform(30, 60), 0), Vector3(generateUniform(0, 0), generateUniform(0, 0), generateUniform(0, 0)), Vector3(0, 0, 0), 0.998, 5);
					aux->setVida(10.0);

				}
				else {
					if (distribucion == TRAYECTORIA) {
						aux = new Particle(ball->getPos(), ball->getVel(), Vector3(0), 0.998, 1.0);

					}
				}

			}
			tiempogeneracion = 0;
			aux->settiempo(tiempototal);
			particulas.push_back(aux);

		}
	}
}

void Generador::Integrate(double t)
{
	list<Particle*> p;
	p.clear();

	for (auto e : particulas) {
		e->integrate(t);
		if (tiempototal >= e->tiempo()) {
			p.push_back(e);
		}
		else {
			Vector3 lim = e->getPos() - iniPos;
			if (lim.y >= AREA_Y || lim.x >= AREA_X)p.push_back(e);
		}

	}

	for (auto d : p) {
		particulas.remove(d);
		delete d;
	}
}

void Generador::update(double t)
{

	tiempototal += t;
	list<Particle*> p;
	Particle* aux;

	if (distribucion == GAUSS) {
		 aux = new Particle(iniPos, Vector3(generateGausssian(0.0, 2), generateGausssian(20, 2), generateGausssian(0, 2)), Vector3(0, 0, 0), 0.998,1.0);
	}
	else {
		aux = new Particle(iniPos, Vector3(generateUniform(-20,20), generateUniform(30, 40), generateUniform(0, 2)), Vector3(0, 0, 0), 0.998,1.0);
	}

	aux->settiempo(tiempototal);
	particulas.push_back(aux);
	
	p.clear();

	for (auto e : particulas) {
		e->integrate(t);
		if (tiempototal >= e->tiempo()) {
			p.push_back(e);
		}
		else {
			Vector3 lim = e->getPos() - iniPos;
			if (lim.y >= AREA_Y || lim.x >= AREA_X)p.push_back(e);
		}
	
	}

	for (auto d : p) {
		particulas.remove(d);
		delete d;
	}
}

void Generador::reset()
{
	for (auto p : particulas) {
		if (p != nullptr) {
			p->settiempo(-1);
		}
	}
}

float Generador::generateGausssian(float mean, float stddev)
{
	static std::default_random_engine generator;
	std::normal_distribution<float>distribution(mean, stddev);
	return distribution(generator);
}

float Generador::generateUniform(float min, float max)
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_real_distribution<> distrib(min, max);
	return distrib(gen);
}
