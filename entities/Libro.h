#ifndef LIBRO
#define LIBRO

#include "Material.h"


class Libro : public Material
{
private:
    string autor;
    int cantPag;
public:
    Libro(string codigo, string titulo, int anioPublicado, string autor, int cantPag);
    string getAutor();
    int getCantPag();
    void setAutor(string autor);
    void setCantPag(int cantPag);
    ~Libro() override;

    string getTipo() override;
};













#endif