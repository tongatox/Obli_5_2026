#ifndef LECTOR
#define LECTOR

#include <string>
using namespace std;

#include "Usuario.h"

class Lector : public Usuario
{
private:
    Fecha fechRegistro;

public:
    Lector(string numid, string nombre, string contraseña);
    Fecha getFechRegistro();
    void setFechRegistro(Fecha fechRegistro);
    ~Lector();
};

#endif