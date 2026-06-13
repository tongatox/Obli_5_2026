#include "Factory.h"

#include "ControladorRegistrarUsuario.h"
#include "ControladorRegistrarMaterial.h"
#include "ControladorRegistrarPrestamo.h"
#include "ControladorSesion.h"
#include "ControladorConsultarPrestamo.h"
#include "ControladorVerInfoMateriales.h"

Factory *Factory::instancia = NULL;

Factory::Factory()
{
}

Factory *Factory::getInstancia()
{
    if (instancia == NULL)
        instancia = new Factory();
    return instancia;
}

IControladorRegistrarUsuario *Factory::getIControladorRegistrarUsuario()
{
    return new ControladorRegistrarUsuario();
}

IControladorRegistrarMaterial *Factory::getIControladorRegistrarMaterial()
{
    return new ControladorRegistrarMaterial();
}

IControladorRegistrarPrestamo *Factory::getIControladorRegistrarPrestamo()
{
    return new ControladorRegistrarPrestamo();
}

IControladorSesion *Factory::getIControladorSesion()
{
    return new ControladorSesion();
}

IControladorConsultarPrestamo *Factory::getIControladorConsultarPrestamo()
{
    return new ControladorConsultarPrestamo();
}

IControladorVerMateriales *Factory::getIControladorVerMateriales()
{
    return new ControladorVerInfoMateriales();
}

Factory::~Factory()
{
}