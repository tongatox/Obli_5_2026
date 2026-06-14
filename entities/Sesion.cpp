#include "Sesion.h"

Sesion* Sesion::instance = nullptr;

Sesion* Sesion::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Sesion();
    }
    return instance;
}


Sesion::Sesion()
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
    if (u == nullptr)
    {
        this->sesion = false;
        this->u = nullptr;
    }
    this->u = u;
    this->sesion = true;
}