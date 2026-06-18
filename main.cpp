#include "menu/menu.h"
#include "cargarDatos.h"

#include "factory/Factory.h"
#include "interfaces/controllers/IControladorRegistrarUsuario.h"
#include "interfaces/controllers/IControladorRegistrarMaterial.h"
#include "interfaces/controllers/IControladorRegistrarPrestamo.h"
#include "interfaces/controllers/IControladorVerInfoMaterial.h"
#include "interfaces/controllers/IControladorSesion.h"
#include "interfaces/controllers/IControladorConsultarPrestamo.h"
#include "entities/Sesion.h"


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
