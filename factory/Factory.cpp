#include "Factory.h"


#include "../controllers/ControladorRegistrarUsuario.h"
#include "../controllers/ControladorRegistrarMaterial.h"
#include "../controllers/ControladorRegistrarPrestamo.h"
#include "../controllers/ControladorVerInfoMaterial.h"
#include "../controllers/ControladorSesion.h"
#include "../controllers/ControladorConsultarPrestamo.h"

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

IControladorVerInfoMaterial *Factory::getIControladorVerInfoMaterial()
{
    return new ControladorVerInfoMaterial();    
}

IControladorSesion *Factory::getIControladorSesion()
{
    return new ControladorSesion();
}

IControladorConsultarPrestamo *Factory::getIControladorConsultarPrestamo()
{
    return new ControladorConsultarPrestamo();
}

Factory::~Factory()
{
}