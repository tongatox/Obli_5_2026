#ifndef ICONTROLADORREGISTRARUSUARIO_H
#define ICONTROLADORREGISTRARUSUARIO_H

#include "Fecha.h"
#include "Usuario.h"

class IControladorRegistrarUsuario
{
public:
    virtual void registrarLector(int numId, string nombre, string contraseña, Fecha fechaRegistro) = 0;
    virtual void registrarFuncionario(int numId, string nombre, string contraseña, int numEmp) = 0;
    virtual ~IControladorRegistrarUsuario() = default;
};

#endif