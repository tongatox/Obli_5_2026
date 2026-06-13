#ifndef FACTORY
#define FACTORY

#include "IControladorRegistrarUsuario.h"
#include "IControladorRegistrarMaterial.h"
#include "IControladorRegistrarPrestamo.h"
#include "IControladorSesion.h"
#include "IControladorConsultarPrestamo.h"
#include "IControladorVerMateriales.h"

class Factory
{
private:
    static Factory *instancia;
    Factory();

public:
    static Factory * getInstancia();
    IControladorRegistrarUsuario * getIControladorRegistrarUsuario();
    IControladorRegistrarMaterial* getIControladorRegistrarMaterial();
    IControladorRegistrarPrestamo* getIControladorRegistrarPrestamo();
    IControladorSesion* getIControladorSesion();
    IControladorConsultarPrestamo *getIControladorConsultarPrestamo();
    IControladorVerMateriales* getIControladorVerMateriales();
    ~Factory();
};

#endif