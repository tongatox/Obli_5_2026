#ifndef CONTROLADORREGISTRARUSUARIO_H
#define CONTROLADORREGISTRARUSUARIO_H

#include "../interfaces/IControladorRegistrarUsuario.h"
#include "../collections/UsuarioCollection.h"
#include "../datatypes/Fecha.h"
#include "../entities/Usuario.h"
#include "../entities/Lector.h"
#include "../entities/Funcionario.h"
#include <string>

using namespace std;

class ControladorRegistrarUsuario : public IControladorRegistrarUsuario
{
private:
    string numId;
    string nombre;
    string contraseña;
    Fecha fechaRegistro;
    int numEmp;

public:
    void registrarLector(string numId, string nombre, string contraseña, Fecha fechaRegistro) override;
    void cancelarLector() override;
    void confirmarLector() override;
    void registrarFuncionario(string numId, string nombre, string contraseña, int numEmp) override;
    void cancelarFuncionario() override;
    void confirmarFuncionario() override;
};

#endif