#ifndef CONTROLADORVERINFOMATERIAL_H
#define CONTROLADORVERINFOMATERIAL_H

#include "../interfaces/IControladorVerInfoMaterial.h"
#include "../entities/Material.h"
#include <map>
#include <string>

using namespace std;

class ControladorVerInfoMaterial : public IControladorVerInfoMaterial
{
private:
    string codigoMaterial;

public:
    map<string, Material*> consultarListaMaterial() override;
    Material* seleccionarMaterial(string codigo) override;
    Material* verDetalleMaterial() override;
};

#endif
