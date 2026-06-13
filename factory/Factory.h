#ifndef FACTORY
#define FACTORY

#include "../interfaces/controllers/IControladorRegistrarUsuario.h"
#include "../interfaces/controllers/IControladorRegistrarMaterial.h"
#include "../interfaces/controllers/IControladorRegistrarPrestamo.h"
#include "../interfaces/controllers/IControladorVerInfoMaterial.h"
#include "../interfaces/controllers/IControladorSesion.h"
#include "../interfaces/controllers/IControladorConsultarPrestamo.h"

class Factory
{
private:
    static Factory *instancia;
    Factory();

public:
    static Factory *getInstancia();
    IControladorRegistrarUsuario *getIControladorRegistrarUsuario();
    IControladorRegistrarMaterial *getIControladorRegistrarMaterial();
    IControladorRegistrarPrestamo *getIControladorRegistrarPrestamo();
    IControladorVerInfoMaterial *getIControladorVerInfoMaterial();
    IControladorSesion *getIControladorSesion();
    IControladorConsultarPrestamo *getIControladorConsultarPrestamo();
    ~Factory();
};

#endif