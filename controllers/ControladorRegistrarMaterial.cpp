#include "ControladorRegistrarMaterial.h"

#include "../collections/MaterialCollection.h"
#include "../entities/Libro.h"
#include "../entities/Revista.h"



void ControladorRegistrarMaterial::registrarLibro(string codigo, string titulo, int anioPublicacion, string autor, int cantPag)
{
    this->codigo = codigo;
    this->titulo = titulo;
    this->anioPublicacion = anioPublicacion;
    this->autor = autor;
    this->cantPag = cantPag;
}

void ControladorRegistrarMaterial::cancelarLibro()
{
    this->codigo = "";
    this->titulo = "";
    this->anioPublicacion = 0;
    this->autor = "";
    this->cantPag = 0;
}

void ControladorRegistrarMaterial::confirmarLibro()
{
    MaterialCollection* mc = MaterialCollection::getInstance();
    Libro* l = new Libro(this->codigo, this->titulo, this->anioPublicacion, this->autor, this->cantPag);
    mc->agregarMaterial(l);
}

void ControladorRegistrarMaterial::registrarRevista(string codigo, string titulo, int anioPublicacion, int numEdi , bool esMensual )
{
    this->codigo = codigo;
    this->titulo = titulo;
    this->anioPublicacion = anioPublicacion;
    this->numEdi = numEdi;
    this->esMensual = esMensual;
}

void ControladorRegistrarMaterial::cancelarRevista()
{
    this->codigo = "";
    this->titulo = "";
    this->anioPublicacion = 0;
    this->numEdi = 0;
    this->esMensual = false;
}

void ControladorRegistrarMaterial::confirmarRevista()
{
    MaterialCollection* mc = MaterialCollection::getInstance();
    Revista* r = new Revista(this->codigo, this->titulo, this->anioPublicacion, this->numEdi, this->esMensual);
    mc->agregarMaterial(r);
}

