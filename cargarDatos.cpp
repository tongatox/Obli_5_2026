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

    // Lectores
    Lector* l1 = new Lector("1", "Iván Rodríguez",    "1234", Fecha(10, 3, 2022));
    Lector* l2 = new Lector("2", "Carlos Fidalgo",  "1234", Fecha(5,  7, 2021));
    Lector* l3 = new Lector("3", "Sergio Martinez",   "1234", Fecha(20, 1, 2023));
    uc->agregarUsuario(l1);
    uc->agregarUsuario(l2);
    uc->agregarUsuario(l3);

    // Funcionarios
    Funcionario* f1 = new Funcionario("4", "Gastón Etcheverre",  "func123", 1001);
    Funcionario* f2 = new Funcionario("5", "Matías Pérez",   "func123", 1002);
    uc->agregarUsuario(f1);
    uc->agregarUsuario(f2);
    
    // Libros
    Libro* lb1 = new Libro("LIB1", "The C Programming Language", 1, "Brian Kernighan y Dennis Ritchie", 272);
    Libro* lb2 = new Libro("LIB2", "Clean Code", 2, "Robert C. Martin", 464);
    Libro* lb3 = new Libro("LIB3", "Effective C++", 3, "Scott Meyers", 320);
    mc->agregarMaterial(lb1);
    mc->agregarMaterial(lb2);
    mc->agregarMaterial(lb3);
    
    // Revistas
    Revista* r1 = new Revista("REV1", "Communications of the ACM", 1, 101, true);
    Revista* r2 = new Revista("REV2", "IEEE Software", 2, 102, true);
    Revista* r3 = new Revista("REV3", "Linux Journal", 3, 103, false);
    mc->agregarMaterial(r1);
    mc->agregarMaterial(r2);
    mc->agregarMaterial(r3);

    // Prestamos
    PrestamoCollection* pc = PrestamoCollection::getInstance();

    Prestamo* p1 = new Prestamo(Fecha(1, 6, 2026), 14);
    p1->setId(1);
    p1->agregarMaterial(lb1);
    l1->agregarPrestamo(p1);
    pc->agregarPrestamo(p1);

    Prestamo* p2 = new Prestamo(Fecha(3, 6, 2026), 7);
    p2->setId(2);
    p2->agregarMaterial(r1);
    l2->agregarPrestamo(p2);
    pc->agregarPrestamo(p2);

    Prestamo* p3 = new Prestamo(Fecha(10, 6, 2026), 14);
    p3->setId(3);
    p3->agregarMaterial(lb3);
    l3->agregarPrestamo(p3);
    pc->agregarPrestamo(p3);
}
