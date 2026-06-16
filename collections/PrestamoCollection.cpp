#include "PrestamoCollection.h"

PrestamoCollection *PrestamoCollection::instance = nullptr;

PrestamoCollection::PrestamoCollection()
{
}

PrestamoCollection *PrestamoCollection::getInstance()
{
    if (instance == nullptr)
        instance = new PrestamoCollection();
    return instance;
}

map<int, Prestamo*> PrestamoCollection::listar()
{
    return this->prestamos;
}

Prestamo* PrestamoCollection::buscarPrestamo(int id)
{
    map<int, Prestamo*>::iterator it = this->prestamos.find(id);
    if (it != this->prestamos.end())
    {
        return it->second;
    }
    return nullptr;
}

void PrestamoCollection::agregarPrestamo(Prestamo* prestamo)
{
    this->prestamos[prestamo->getId()] = prestamo;
}

void PrestamoCollection::actualizarPrestamo(Prestamo* prestamo)
{
    Prestamo* existente = this->buscarPrestamo(prestamo->getId());
    if (existente != nullptr)
    {
        existente->setId(prestamo->getId());
    }
}

void PrestamoCollection::eliminarPrestamo(int id)
{
    Prestamo* prestamo = this->buscarPrestamo(id);
    if (prestamo != nullptr)
    {
        delete prestamo;
        this->prestamos.erase(id);
    }
}

bool PrestamoCollection::existePrestamo(int id)
{
    return this->prestamos.find(id) != this->prestamos.end();
}

PrestamoCollection::~PrestamoCollection()
{
    for (map<int, Prestamo*>::iterator it = this->prestamos.begin(); it != this->prestamos.end(); ++it)
    {
        delete it->second;
    }
    this->prestamos.clear();
}