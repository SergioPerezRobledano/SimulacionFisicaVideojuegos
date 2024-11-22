#include "GeneradorFlotacion.h"

Vector3 GeneradorFlotacion::setForce(Particle* p, double t)
{
    return fuerzaFlotacion(p);
}
