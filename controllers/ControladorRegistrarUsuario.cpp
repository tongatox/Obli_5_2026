#include "ControladorRegistrarUsuario.h"
#include "../collections/UsuarioCollection.h"
#include "../datatypes/Fecha.h"
#include "../entities/Lector.h"
#include "../entities/Funcionario.h"

void ControladorRegistrarUsuario::registrarLector(string numId, string nombre, string contraseña, Fecha fechaRegistro)
{
    this->numId = numId;
    this->nombre = nombre;
    this->contraseña = contraseña;
    this->fechaRegistro = fechaRegistro;
}

void ControladorRegistrarUsuario::cancelarLector()
{
    this->numId = "";
    this->nombre = "";
    this->contraseña = "";
    this->fechaRegistro = Fecha(0, 0, 0);
}

void ControladorRegistrarUsuario::confirmarLector()
{
    UsuarioCollection* uc = UsuarioCollection::getInstance();
    Lector* l = new Lector(this->numId, this->nombre, this->contraseña, this->fechaRegistro);
    uc->agregarUsuario(l);
}

void ControladorRegistrarUsuario::registrarFuncionario(string numId, string nombre, string contraseña, int numEmp)
{
    this->numId = numId;
    this->nombre = nombre;
    this->contraseña = contraseña;
    this->numEmp = numEmp;
}


void ControladorRegistrarUsuario::cancelarFuncionario()
{
    this->numId = "";
    this->nombre = "";
    this->contraseña = "";
    this->numEmp = 0;
}

void ControladorRegistrarUsuario::confirmarFuncionario()
{
    UsuarioCollection* uc = UsuarioCollection::getInstance();
    Funcionario* f = new Funcionario(this->numId, this->nombre, this->contraseña, this->numEmp);
    uc->agregarUsuario(f);
}
