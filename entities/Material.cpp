#include "Material.h"

Material::Material(string codigo, string titulo, int anioPublicado)
{
    this->codigo = codigo;
    this->titulo = titulo;
    this->anioPublicado = anioPublicado;
}

void Material::setCodigo(string codigo)
{
    this->codigo = codigo;
}

string Material::getCodigo()
{
    return codigo;
}

void Material::setTitulo(string titulo)
{
    this->titulo = titulo;
}

string Material::getTitulo()
{
    return titulo;
}

void Material::setAnioPubli(int anioPublicado)
{
    this->anioPublicado = anioPublicado;
}

int Material::getAnioPubli()
{
    return anioPublicado;
}

Material::~Material()
{
}