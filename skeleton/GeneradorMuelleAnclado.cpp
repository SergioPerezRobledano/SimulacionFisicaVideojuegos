#include "GeneradorMuelleAnclado.h"

Vector3 GeneradorMuelleAnclado::setForce(Particle* p, double t)
{
    return fuerzaMuelle(p);
}

Vector3 GeneradorMuelleAnclado::setForce(SolidoRigido* p, double t)
{
    return fuerzaMuelle(p);
}
