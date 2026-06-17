#include "Revista.h"


Revista::Revista(string codigo, string titulo, int anioPublicado, int numEdi, bool esMensual) : Material(codigo, titulo, anioPublicado)
{
    this->numEdi = numEdi;
    this->esMensual = esMensual;
}

int Revista::getNumEdi()
{
    return this->numEdi;
}

bool Revista::getEsMensual()
{
    return this->esMensual;
}

void Revista::setNumEdi(int numEdi)
{
    this->numEdi = numEdi;
}

void Revista::setEsMensual(bool esMensual)
{
    this->esMensual = esMensual;
}

Revista::~Revista()
{

}

string Revista::getTipo()
{
    return "Revista";
}