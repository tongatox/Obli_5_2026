#ifndef ICONTROLADORREGISTRARMATERIAL_H
#define ICONTROLADORREGISTRARMATERIAL_H

#include <string>

using namespace std;

class IControladorRegistrarMaterial
{
public:
    virtual void registrarLibro(string codigo, string titulo, int anioPublicacion, string autor, int cantPag) = 0;
    virtual void cancelarLibro() = 0;
    virtual void confirmarLibro() = 0;

    virtual void registrarRevista(string codigo, string titulo, int anioPublicacion, int numEdi, bool esMensual) = 0;
    virtual void cancelarRevista() = 0;
    virtual void confirmarRevista() = 0;

    virtual ~IControladorRegistrarMaterial() = default;
};

#endif
