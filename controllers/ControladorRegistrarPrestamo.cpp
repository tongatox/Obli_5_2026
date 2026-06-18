#include "ControladorRegistrarPrestamo.h"

#include "../collections/UsuarioCollection.h"
#include "../collections/MaterialCollection.h"
#include "../collections/PrestamoCollection.h"
#include "../entities/Lector.h"
#include "../entities/Prestamo.h"


void ControladorRegistrarPrestamo::registrarPrestamo(Fecha fechaPres, int diasPermi, string numId, string codigo)
{
    this->fechaPres = fechaPres;
    this->diasPermi = diasPermi;
    this->numId = numId;
    this->codigo = codigo;
}

void ControladorRegistrarPrestamo::cancelarPrestamo()
{
    this->fechaPres = Fecha(0, 0, 0);
    this->diasPermi = 0;
    this->numId = "";
    this->codigo = "";
}

void ControladorRegistrarPrestamo::confirmarPrestamo()
{
    UsuarioCollection* uc = UsuarioCollection::getInstance();
    MaterialCollection* mc = MaterialCollection::getInstance();
    PrestamoCollection* pc = PrestamoCollection::getInstance();

    Usuario* usuario = uc->buscarUsuario(this->numId);
    Material* material = mc->buscarMaterial(this->codigo);

    if (usuario != nullptr && material != nullptr)
    {
        Prestamo* prestamo = new Prestamo(this->fechaPres, this->diasPermi);
        prestamo->agregarMaterial(material);
        Lector* lector = dynamic_cast<Lector*>(usuario);
        if (lector != nullptr)
        {
            lector->agregarPrestamo(prestamo);
        }
        pc->agregarPrestamo(prestamo);
    }
}

