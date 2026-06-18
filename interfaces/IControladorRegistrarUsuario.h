#ifndef ICONTROLADORREGISTRARUSUARIO_H
#define ICONTROLADORREGISTRARUSUARIO_H

#include "../datatypes/Fecha.h"
#include "../entities/Usuario.h"
#include <string>
using namespace std;

class IControladorRegistrarUsuario
{
public:
    virtual void registrarLector(string numId, string nombre, string contraseña, Fecha fechaRegistro) = 0;
    virtual void cancelarLector() = 0;
    virtual void confirmarLector() = 0;
    virtual void registrarFuncionario(string numId, string nombre, string contraseña, int numEmp) = 0;
    virtual void cancelarFuncionario() = 0;
    virtual void confirmarFuncionario() = 0;
    virtual ~IControladorRegistrarUsuario() = default;
};

#endif