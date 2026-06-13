#ifndef PRESTAMO
#define PRESTAMO

#include "Material.h"
#include "../datatypes/Fecha.h"

class Prestamo
{
private:
    int id;
    Fecha fechasPres;
    int diasPermi;
    Material * material;
public:
    Prestamo(Fecha fechasPres, int diasPermi);
    int getId();
    void setId(int id);
    Fecha getFechasPres();
    int getDiasPermi();
    void setFechaPres(Fecha fechaPres);
    void setDiasPermi(int diasPermi);
    ~Prestamo();

    Material *getMaterial();
    void agregarMaterial(Material * material);
    
};

#endif