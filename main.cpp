#include "menu/menu.h"
#include "cargarDatos.h"

#include "factory/Factory.h"
#include "IControladorRegistrarUsuario.h"
#include "IControladorRegistrarMaterial.h"
#include "IControladorRegistrarPrestamo.h"
#include "IControladorVerInfoMaterial.h"
#include "IControladorSesion.h"
#include "IControladorConsultarPrestamo.h"
#include "Sesion.h"


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
    s = Sesion::getInstance();
    f = Factory::getInstancia();
    icru = f->getIControladorRegistrarUsuario();
    icrm = f->getIControladorRegistrarMaterial();
    icrp = f->getIControladorRegistrarPrestamo();
    icvim = f->getIControladorVerInfoMaterial();
    ics = f->getIControladorSesion();
    iccp = f->getIControladorConsultarPrestamo();

    cargarDatos();
    menuAutenticacion();
    return 0;
}
