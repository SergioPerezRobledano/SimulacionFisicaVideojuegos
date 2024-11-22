#include "GeneradorMuelle.h"

Vector3 GeneradorMuelle::setForce(Particle* p1,Particle* p2, double t)
{
    return fuerzaMuelle(p1,p2);
}
