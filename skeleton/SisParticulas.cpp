#include "SisParticulas.h"

void SisParticulas::Generate(double t)
{
	for (auto e : generador) {
		e->Generate(t);
	}
}

void SisParticulas::Integrate(double t)
{
	for (auto e : generador) {
		e->Integrate(t);
	}
}

void SisParticulas::update(double t)
{
	for (auto e : generador) {
		e->update(t);
	}
}
