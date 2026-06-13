#include "ControladorVerInfoMaterial.h"
#include "../collections/MaterialCollection.h"

map<string, Material*> ControladorVerInfoMaterial::consultarListaMaterial()
{
    
}

Material* ControladorVerInfoMaterial::seleccionarMaterial(string codigo)
{
    this->codigoMaterial = codigo;
    MaterialCollection* mc = MaterialCollection::getInstance();
    return mc->buscarMaterial(this->codigoMaterial);
}

Material* ControladorVerInfoMaterial::verDetalleMaterial()
{
    MaterialCollection* mc = MaterialCollection::getInstance();
    return mc->buscarMaterial(this->codigoMaterial);
}
