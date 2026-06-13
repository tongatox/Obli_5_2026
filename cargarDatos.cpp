#include "cargarDatos.h"
#include "datatypes/Fecha.h"
#include "entities/Lector.h"
#include "entities/Funcionario.h"
#include "entities/Libro.h"
#include "entities/Revista.h"
#include "entities/Prestamo.h"
#include "collections/UsuarioCollection.h"
#include "collections/MaterialCollection.h"
#include "collections/PrestamoCollection.h"

void cargarDatos()
{
    UsuarioCollection*  uc = UsuarioCollection::getInstance();
    MaterialCollection* mc = MaterialCollection::getInstance();

    // -------------------------------------------------------------------------
    // Carga de datos para los usuairos que son lectores
    // -------------------------------------------------------------------------
    Lector* l1 = new Lector("111", "Ana Garcia",    "1234", Fecha(10, 3, 2022));
    Lector* l2 = new Lector("222", "Carlos Lopez",  "1234", Fecha(5,  7, 2021));
    Lector* l3 = new Lector("333", "Maria Perez",   "1234", Fecha(20, 1, 2023));

    uc->agregarUsuario(l1);
    uc->agregarUsuario(l2);
    uc->agregarUsuario(l3);

    // -------------------------------------------------------------------------
    // Carga de datos para los usuarios que son funcionarios
    // -------------------------------------------------------------------------
    Funcionario* f1 = new Funcionario("444", "Juan Torres",  "func123", 1001);
    Funcionario* f2 = new Funcionario("555", "Laura Diaz",   "func123", 1002);

    uc->agregarUsuario(f1);
    uc->agregarUsuario(f2);

    // -------------------------------------------------------------------------
    // Carga de datos para los materiales que son libros
    // -------------------------------------------------------------------------
    Libro* lb1 = new Libro("LIB001", "El Quijote",              1605, "Miguel de Cervantes", 863);
    Libro* lb2 = new Libro("LIB002", "Cien anios de soledad",   1967, "Gabriel Garcia Marquez", 432);
    Libro* lb3 = new Libro("LIB003", "1984",                    1949, "George Orwell", 328);

    mc->agregarMaterial(lb1);
    mc->agregarMaterial(lb2);
    mc->agregarMaterial(lb3);

    // -------------------------------------------------------------------------
    // Carga de datos para los materiales que son revistas
    // -------------------------------------------------------------------------
    Revista* r1 = new Revista("REV001", "National Geographic", 2024, 387, true);
    Revista* r2 = new Revista("REV002", "Scientific American", 2023, 412, true);
    Revista* r3 = new Revista("REV003", "Codigo Facilito",     2022, 18,  false);

    mc->agregarMaterial(r1);
    mc->agregarMaterial(r2);
    mc->agregarMaterial(r3);

    // -------------------------------------------------------------------------
    // Carga de datos para algunos prestamos
    // -------------------------------------------------------------------------
    PrestamoCollection* pc = PrestamoCollection::getInstance();

    Prestamo* p1 = new Prestamo(Fecha(1, 6, 2026), 14);
    p1->agregarMaterial(lb1);
    l1->agregarPrestamo(p1);
    pc->agregarPrestamo(p1);

    Prestamo* p2 = new Prestamo(Fecha(3, 6, 2026), 7);
    p2->agregarMaterial(r1);
    l2->agregarPrestamo(p2);
    pc->agregarPrestamo(p2);

    Prestamo* p3 = new Prestamo(Fecha(10, 6, 2026), 14);
    p3->agregarMaterial(lb3);
    l3->agregarPrestamo(p3);
    pc->agregarPrestamo(p3);
}
