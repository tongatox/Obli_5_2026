#ifndef CONTROLADORCONSULTARPRESTAMO_H
#define CONTROLADORCONSULTARPRESTAMO_H

#include "../interfaces/IControladorConsultarPrestamo.h"

class ControladorConsultarPrestamo : public IControladorConsultarPrestamo
{
public:
    map<int, Prestamo*> consultarPrestamos() override;
    Prestamo* consultarPrestamo(int id) override;
};

#endif
