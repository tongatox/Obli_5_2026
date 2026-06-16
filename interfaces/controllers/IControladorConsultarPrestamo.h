#ifndef ICONTROLADORCONSULTARPRESTAMO_H
#define ICONTROLADORCONSULTARPRESTAMO_H

#include <map>
#include "../../entities/Prestamo.h"

using namespace std;

class IControladorConsultarPrestamo
{
public:
    virtual map<int, Prestamo*> consultarTodos() = 0;
    virtual Prestamo* consultarPrestamo(int id) = 0;
    virtual ~IControladorConsultarPrestamo() = default;
};

#endif
