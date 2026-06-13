#ifndef SESION
#define SESION

#include "Usuario.h"

class Sesion
{
private:
    static Sesion *instance;
    bool sesion;
    Usuario * u;
    Sesion();
public:
    static Sesion *getInstance();
    bool getSesion();
    ~Sesion();

    Usuario * getUsuarioSesion();
    void setUsuarioSesion(Usuario * u);

};



#endif