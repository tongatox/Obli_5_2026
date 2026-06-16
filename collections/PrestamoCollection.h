#ifndef PRESTAMOCOLLECTION
#define PRESTAMOCOLLECTION

#include <map>
#include "../entities/Prestamo.h"

using namespace std;

class PrestamoCollection
{
private:
    static PrestamoCollection *instance;
    map<int, Prestamo*> prestamos;
    PrestamoCollection();

public:
    static PrestamoCollection* getInstance();
    map<int, Prestamo*> listar();
    Prestamo* buscarPrestamo(int id);
    void agregarPrestamo(Prestamo* prestamo);
    void actualizarPrestamo(Prestamo* prestamo);
    void eliminarPrestamo(int id);
    bool existePrestamo(int id);

    ~PrestamoCollection();
};

#endif