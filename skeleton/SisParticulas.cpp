#include "SisParticulas.h"

void SisParticulas::Generate(double t)
{
	for (auto e : generador) {
		e->Generate(t);
	}

	for (auto e : Levelgenerador) {
		e->Generate(t);
	}
}

void SisParticulas::Integrate(double t)
{
	for (auto e : generador) {
		e->Integrate(t);
	}
	for (auto e : Levelgenerador) {
		e->Integrate(t);
	}
	for (auto ma : particulasMA) {
		ma->integrate(t);
	}
	if (particulasM.first != nullptr && particulasM.second != nullptr) {
		particulasM.first->integrate(t);
		particulasM.second->integrate(t);
	}

}

void SisParticulas::update(double t)
{
	for (auto e : generador) {
		e->update(t);
	}
}
