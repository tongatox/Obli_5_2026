#include "Sesion.h"

Sesion::Sesion(bool sesion)
{
    this->sesion = NULL;
}

bool Sesion::getSesion()
{
    return this->sesion;
}

Sesion::~Sesion()
{
}

Usuario * Sesion::getUsuarioSesion()
{
    return this->u;
}

void Sesion::setUsuarioSesion(Usuario * u)
{
    this->u = u;
    this->sesion = true;
}