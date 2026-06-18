#include "ControladorSesion.h"

#include "../collections/UsuarioCollection.h"
#include "../entities/Usuario.h"
#include "../entities/Sesion.h"

bool ControladorSesion::ingresarDatos(string numId, string contraseña)
{
    this->numId = numId;
    this->contraseña = contraseña;
    
    UsuarioCollection* uc = UsuarioCollection::getInstance();
    Usuario* usuario = uc->buscarUsuario(numId);
    if (usuario != nullptr && usuario->validarContraseña(contraseña))
    {
        // Inicio de sesión exitoso
        Sesion::getInstance()->setUsuarioSesion(usuario);
        return true;
    }

    return false;
}

void ControladorSesion::cerrarSesion()
{
    Sesion::getInstance()->setUsuarioSesion(nullptr);
}

void ControladorSesion::cancelar()
{
    this->numId = "";
    this->contraseña = "";
}
