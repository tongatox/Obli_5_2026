#include "ControladorConsultarPrestamo.h"
#include "../collections/PrestamoCollection.h"

map<int, Prestamo*> ControladorConsultarPrestamo::consultarTodos()
{
    return PrestamoCollection::getInstance()->listar();
}

Prestamo* ControladorConsultarPrestamo::consultarPrestamo(int id)
{
    return PrestamoCollection::getInstance()->buscarPrestamo(id);
}
