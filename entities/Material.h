#ifndef MATERIAL
#define MATERIAL

#include <string>

using namespace std;

class Material
{
private:
    string codigo;
    string titulo;
    int anioPublicado;
public:
    Material(string codigo, string titulo, int anioPublicado);
    void setCodigo(string codigo);
    string getCodigo();
    void setTitulo(string titulo);
    string getTitulo();
    void setAnioPubli(int anioPublicado);
    int getAnioPubli();
    virtual ~Material();

    virtual string getTipo() = 0;

};

#endif