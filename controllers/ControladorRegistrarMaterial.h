#ifndef CONTROLADORREGISTRARMATERIAL_H
#define CONTROLADORREGISTRARMATERIAL_H

#include "../interfaces/IControladorRegistrarMaterial.h"
#include "../collections/MaterialCollection.h"
#include "../datatypes/Fecha.h"
#include "../entities/Libro.h"
#include "../entities/Revista.h"
#include <string>
using namespace std;

class ControladorRegistrarMaterial : public IControladorRegistrarMaterial
{
    private:
    string codigo;
    string titulo;
    int anioPublicacion;
    string autor;
    int cantPag;
    int numEdi;
    bool esMensual;
public:
    void registrarLibro(string codigo, string titulo, int anioPublicacion, string autor, int cantPag) override;
    void cancelarLibro() override;
    void confirmarLibro() override;
    void registrarRevista(string codigo, string titulo, int anioPublicacion, int numEdi, bool esMensual) override;
    void cancelarRevista() override;
    void confirmarRevista() override;
};

#endif