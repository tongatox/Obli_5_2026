#ifndef ICONTROLADORSESION_H
#define ICONTROLADORSESION_H

#include <string>
using namespace std;

class IControladorSesion
{
public:
    virtual bool ingresarDatos(string numId, string contraseña) = 0;
    virtual void cerrarSesion() = 0;
    virtual void cancelar() = 0;
    virtual ~IControladorSesion() = default;
};

#endif
