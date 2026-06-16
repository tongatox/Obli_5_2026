#ifndef CONTROLADORCONSULTARPRESTAMO_H
#define CONTROLADORCONSULTARPRESTAMO_H

#include "../interfaces/controllers/IControladorConsultarPrestamo.h"

class ControladorConsultarPrestamo : public IControladorConsultarPrestamo
{
public:
    map<int, Prestamo*> consultarTodos() override;
    Prestamo* consultarPrestamo(int id) override;
};

#endif
