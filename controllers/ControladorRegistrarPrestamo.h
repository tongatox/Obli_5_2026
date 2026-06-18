#ifndef CONTROLADORREGISTRARPRESTAMO
#define CONTROLADORREGISTRARPRESTAMO

#include "../interfaces/IControladorRegistrarPrestamo.h"
#include "../datatypes/Fecha.h"
#include "../entities/Lector.h"
#include "../entities/Prestamo.h"
#include "../collections/UsuarioCollection.h"
#include <string>
using namespace std;


class ControladorRegistrarPrestamo : public IControladorRegistrarPrestamo
{
private:
    Fecha fechaPres;
    int diasPermi;   
    string numId;
    string codigo; 
public:
    void registrarPrestamo(Fecha fechaPres, int diasPermi, string numId, string codigo);
    void cancelarPrestamo();
    void confirmarPrestamo();
};

#endif
