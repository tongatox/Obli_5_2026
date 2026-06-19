#include "menu/menu.h"
#include "cargarDatos.h"

#include "factory/Factory.h"
#include "interfaces/IControladorRegistrarUsuario.h"
#include "interfaces/IControladorRegistrarMaterial.h"
#include "interfaces/IControladorRegistrarPrestamo.h"
#include "interfaces/IControladorVerInfoMaterial.h"
#include "interfaces/IControladorSesion.h"
#include "interfaces/IControladorConsultarPrestamo.h"
#include "entities/Sesion.h"
#include "entities/Reloj.h"


Sesion * s;
Factory * f;
IControladorRegistrarUsuario *icru;
IControladorRegistrarMaterial *icrm;
IControladorRegistrarPrestamo *icrp;
IControladorVerInfoMaterial *icvim;
IControladorSesion *ics;
IControladorConsultarPrestamo *iccp;

int main()
{
    cargarDatos();
    menuAutenticacion();
    return 0;
}
