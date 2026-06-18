#ifndef FACTORY
#define FACTORY

#include "../interfaces/IControladorRegistrarUsuario.h"
#include "../interfaces/IControladorRegistrarMaterial.h"
#include "../interfaces/IControladorRegistrarPrestamo.h"
#include "../interfaces/IControladorVerInfoMaterial.h"
#include "../interfaces/IControladorSesion.h"
#include "../interfaces/IControladorConsultarPrestamo.h"

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