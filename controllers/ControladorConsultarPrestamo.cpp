#include "ControladorConsultarPrestamo.h"
#include "../collections/PrestamoCollection.h"

map<int, Prestamo*> ControladorConsultarPrestamo::consultarPrestamos()
{
    return PrestamoCollection::getInstance()->listar();
}

Prestamo* ControladorConsultarPrestamo::consultarPrestamo(int id)
{
    return PrestamoCollection::getInstance()->buscarPrestamo(id);
}
