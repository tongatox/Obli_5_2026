#ifndef ICONTROLADORVERINFOMATERIAL_H
#define ICONTROLADORVERINFOMATERIAL_H

#include <map>
#include <string>
#include "../entities/Material.h"

using namespace std;

class IControladorVerInfoMaterial
{
public:
    virtual map<string, Material*> consultarListaMaterial() = 0;
    virtual Material* seleccionarMaterial(string codigo) = 0;
    virtual Material* verDetalleMaterial() = 0;

    virtual ~IControladorVerInfoMaterial() = default;
};

#endif
