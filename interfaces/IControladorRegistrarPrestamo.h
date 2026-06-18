#ifndef ICONTROLADORREGISTRARPRESTAMO
#define ICONTROLADORREGISTRARPRESTAMO

#include "../datatypes/Fecha.h"
#include "../entities/Prestamo.h"
#include "../collections/UsuarioCollection.h"
#include "../collections/MaterialCollection.h"
#include "../collections/PrestamoCollection.h"
#include <string>
using namespace std;

class IControladorRegistrarPrestamo
{
public:
    virtual void registrarPrestamo(Fecha fechaPres, int diasPermi, string numId, string codigo) = 0;
    virtual void cancelarPrestamo() = 0;
    virtual void confirmarPrestamo() = 0;
    virtual ~IControladorRegistrarPrestamo() = default;
};

#endif