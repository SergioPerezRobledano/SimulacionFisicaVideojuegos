#include "SisParticulas.h"

void SisParticulas::update(double t)
{
	for (auto e : generador) {
		e->update(t);
	}
}
