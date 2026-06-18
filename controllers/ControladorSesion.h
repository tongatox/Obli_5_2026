#ifndef CONTROLADORSESION
#define CONTROLADORSESION

#include "../interfaces/IControladorSesion.h"

class ControladorSesion : public IControladorSesion
{
    private:
        string numId;
        string contraseña;
public:
    bool ingresarDatos(string numId, string contraseña);
    void cerrarSesion();
    void cancelar();
};

#endif
