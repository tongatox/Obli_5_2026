#include "menu.h"

#include <iostream>
#include <string>
#include <map>
#include "../interfaces/controllers/IControladorRegistrarUsuario.h"
#include "../interfaces/controllers/IControladorRegistrarMaterial.h"
#include "../interfaces/controllers/IControladorRegistrarPrestamo.h"
#include "../interfaces/controllers/IControladorVerInfoMaterial.h"
#include "../interfaces/controllers/IControladorSesion.h"
#include "../interfaces/controllers/IControladorConsultarPrestamo.h"
#include "../factory/Factory.h"
#include "../datatypes/Fecha.h"
#include "../collections/UsuarioCollection.h"
#include "../entities/Sesion.h"
#include "../entities/Lector.h"
#include "../entities/Libro.h"
#include "../entities/Revista.h"

using namespace std;

Factory *factory;
IControladorRegistrarUsuario *iConRegistrarUsuario;
IControladorRegistrarMaterial *iConRegistrarMaterial;
IControladorRegistrarPrestamo *iConRegistrarPrestamo;
IControladorVerInfoMaterial *iConVerInfoMaterial;
IControladorConsultarPrestamo *iConConsultarPrestamo;
IControladorSesion *iConSesion;

// -----------------------------------------------------------------------
// Submenú: Registro de funcionario (actor: Funcionario)
// -----------------------------------------------------------------------
static void menuRegistrarFuncionario()
{
    iConRegistrarUsuario = factory->getIControladorRegistrarUsuario();

    cout << "\n--- Registrar Funcionario ---\n";

    string numId, nombre, contrasenia;
    int numEmp;
    cout << "Numero de ID: ";       getline(cin, numId);
    cout << "Nombre: ";             getline(cin, nombre);
    cout << "Contraseña: ";         getline(cin, contrasenia);
    cout << "Numero de empleado: "; cin >> numEmp; cin.ignore();

    iConRegistrarUsuario->registrarFuncionario(numId, nombre, contrasenia, numEmp);
    iConRegistrarUsuario->confirmarFuncionario();
    cout << "Funcionario registrado.\n";
}

// -----------------------------------------------------------------------
// Submenú: Registro de lector (actor: Funcionario)
// -----------------------------------------------------------------------
static void menuRegistrarLector()
{
    iConRegistrarUsuario = factory->getIControladorRegistrarUsuario();

    cout << "\n--- Registrar Lector ---\n";

    string numId, nombre, contrasenia;
    int dia, mes, anio;
    cout << "Numero de ID: "; getline(cin, numId);
    cout << "Nombre: ";       getline(cin, nombre);
    cout << "Contraseña: ";   getline(cin, contrasenia);
    cout << "Fecha de registro (dd mm aaaa): ";
    cin >> dia >> mes >> anio; cin.ignore();

    iConRegistrarUsuario->registrarLector(numId, nombre, contrasenia, Fecha(dia, mes, anio));
    iConRegistrarUsuario->confirmarLector();
    cout << "Lector registrado.\n";
}

// -----------------------------------------------------------------------
// Submenú: Registro de materiales - libro o revista
// -----------------------------------------------------------------------
static void menuRegistrarMaterial()
{
    iConRegistrarMaterial = factory->getIControladorRegistrarMaterial();
    int opcion;

    cout << "\n--- Registrar Material ---\n";
    cout << "1. Libro\n";
    cout << "2. Revista\n";
    cout << "Opcion: ";
    cin >> opcion;
    cin.ignore();

    string codigo, titulo;
    int anio;
    cout << "Codigo: ";  getline(cin, codigo);
    cout << "Titulo: ";  getline(cin, titulo);
    cout << "Anio de publicacion: "; cin >> anio; cin.ignore();

    if (opcion == 1)
    {
        string autor;
        int cantPag;
        cout << "Autor: ";          getline(cin, autor);
        cout << "Cantidad de paginas: "; cin >> cantPag; cin.ignore();

        iConRegistrarMaterial->registrarLibro(codigo, titulo, anio, autor, cantPag);
        iConRegistrarMaterial->confirmarLibro();
        cout << "Libro registrado.\n";
    }
    else if (opcion == 2)
    {
        int numEdi;
        char mensual;
        cout << "Numero de edicion: "; cin >> numEdi; cin.ignore();
        cout << "Es mensual? (s/n): "; cin >> mensual; cin.ignore();

        iConRegistrarMaterial->registrarRevista(codigo, titulo, anio, numEdi, mensual == 's' || mensual == 'S');
        iConRegistrarMaterial->confirmarRevista();
        cout << "Revista registrada.\n";
    }
    else
    {
        cout << "Opcion invalida. Operacion cancelada.\n";
    }
}

// -----------------------------------------------------------------------
// Submenú: Registro de préstamos
// -----------------------------------------------------------------------
static void menuRegistrarPrestamo()
{
    iConRegistrarPrestamo = factory->getIControladorRegistrarPrestamo();

    cout << "\n--- Registrar Prestamo ---\n";

    string numId, codigoMat;
    int dia, mes, anio, diasPermi;

    Usuario* user = Sesion::getInstance()->getUsuarioSesion();
    if (user->getTipo() == "Lector")
    {
        numId = user->getNumid();
        cout << "Lector: " << user->getNombre() << " (" << numId << ")\n";
    }
    else
    {
        cout << "Numero de ID del Lector: ";
        getline(cin, numId);
    }

    cout << "Codigo del Material: ";
    getline(cin, codigoMat);
    cout << "Fecha del prestamo (dd mm aaaa): ";
    cin >> dia >> mes >> anio;
    cout << "Dias permitidos: ";
    cin >> diasPermi;
    cin.ignore();

    iConRegistrarPrestamo->registrarPrestamo(Fecha(dia, mes, anio), diasPermi, numId, codigoMat);
    iConRegistrarPrestamo->confirmarPrestamo();
    cout << "Prestamo registrado.\n";
}

// -----------------------------------------------------------------------
// Submenú: Ver información de material (lector y funcionario)
// -----------------------------------------------------------------------
static void menuVerInfoMaterial()
{
    iConVerInfoMaterial = factory->getIControladorVerInfoMaterial();
    map<string, Material*> todos = iConVerInfoMaterial->consultarListaMaterial();

    if (todos.empty())
    {
        cout << "No hay materiales registrados.\n";
        return;
    }

    cout << "\n--- Materiales disponibles ---\n";
    for (auto const& x : todos)
    {
        Material* m = x.second;
        cout << "[" << m->getTipo() << "] " << m->getCodigo() << " | " << m->getTitulo()
             << " (" << m->getAnioPubli() << ")\n";
    }

    cout << "\nIngrese codigo para ver detalle (Enter para cancelar): ";
    string codigo;
    getline(cin, codigo);
    if (codigo.empty()) return;

    Material* m = iConVerInfoMaterial->seleccionarMaterial(codigo);
    if (m == nullptr)
    {
        cout << "Material no encontrado.\n";
        return;
    }

    cout << "\n--- Detalle del Material ---\n";
    cout << "Tipo   : " << m->getTipo() << "\n";
    cout << "Codigo : " << m->getCodigo() << "\n";
    cout << "Titulo : " << m->getTitulo() << "\n";
    cout << "Anio   : " << m->getAnioPubli() << "\n";

    Libro* lb = dynamic_cast<Libro*>(m);
    if (lb != nullptr)
    {
        cout << "Autor  : " << lb->getAutor() << "\n";
        cout << "Paginas: " << lb->getCantPag() << "\n";
    }

    Revista* rv = dynamic_cast<Revista*>(m);
    if (rv != nullptr)
    {
        cout << "Edicion: " << rv->getNumEdi() << "\n";
        cout << "Mensual: " << (rv->getEsMensual() ? "Si" : "No") << "\n";
    }
}

// -----------------------------------------------------------------------
// Submenú: Consultar préstamos (funcionario - ve todos)
// -----------------------------------------------------------------------
static void menuConsultarPrestamo()
{
    iConConsultarPrestamo = factory->getIControladorConsultarPrestamo();
    map<int, Prestamo*> todos = iConConsultarPrestamo->consultarTodos();

    if (todos.empty())
    {
        cout << "No hay prestamos registrados.\n";
        return;
    }

    cout << "\n--- Prestamos registrados ---\n";
    for (auto const& x : todos)
    {
        Prestamo* p = x.second;
        Fecha f = p->getFechasPres();
        cout << "ID: " << p->getId()
             << " | Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio()
             << " | Dias permitidos: " << p->getDiasPermi();
        if (p->getMaterial() != nullptr)
            cout << " | Material: " << p->getMaterial()->getTitulo();
        cout << "\n";
    }
}

// -----------------------------------------------------------------------
// Submenú: Consultar préstamos del lector en sesion (actor: Lector)
// -----------------------------------------------------------------------
static void menuConsultarMisPrestamos()
{
    Usuario* u = Sesion::getInstance()->getUsuarioSesion();
    Lector* l = dynamic_cast<Lector*>(u);
    if (l == nullptr) return;

    Prestamo** prestamos = l->getPrestamo();
    bool hayPrestamos = false;

    cout << "\n--- Mis Prestamos ---\n";
    for (int i = 0; i < MAX_PRESTAMO; i++)
    {
        if (prestamos[i] == nullptr) break;
        hayPrestamos = true;
        Prestamo* p = prestamos[i];
        Fecha f = p->getFechasPres();
        cout << "ID: " << p->getId()
             << " | Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio()
             << " | Dias: " << p->getDiasPermi();
        if (p->getMaterial() != nullptr)
            cout << " | Material: " << p->getMaterial()->getTitulo();
        cout << "\n";
    }

    if (!hayPrestamos)
        cout << "No tiene prestamos registrados.\n";

    delete[] prestamos;
}

// -----------------------------------------------------------------------
// Menú para el Lector
// -----------------------------------------------------------------------
static void menuLector()
{
    int opcion = 0;
    while (opcion != 3)
    {
        cout << "\n=============================\n";
        cout << "       Menu Lector\n";
        cout << "=============================\n";
        cout << "1. Ver Informacion Material\n";
        cout << "2. Consultar mis Prestamos\n";
        cout << "3. Cerrar Sesion\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
            case 1: menuVerInfoMaterial();     break;
            case 2: menuConsultarMisPrestamos(); break;
            case 3:
                iConSesion = factory->getIControladorSesion();
                iConSesion->cerrarSesion();
                cout << "Sesion cerrada.\n";
                break;
            default: cout << "Opcion invalida.\n"; break;
        }
    }
}

// -----------------------------------------------------------------------
// Menú para el Funcionario
// -----------------------------------------------------------------------
static void menuFuncionario()
{
    int opcion = 0;
    while (opcion != 7)
    {
        cout << "\n=============================\n";
        cout << "      Menu Funcionario\n";
        cout << "=============================\n";
        cout << "1. Registrar Funcionario\n";
        cout << "2. Registrar Lector\n";
        cout << "3. Registrar Material\n";
        cout << "4. Registrar Prestamo\n";
        cout << "5. Ver Informacion Material\n";
        cout << "6. Consultar Prestamos\n";
        cout << "7. Cerrar Sesion\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
            case 1: menuRegistrarFuncionario(); break;
            case 2: menuRegistrarLector();      break;
            case 3: menuRegistrarMaterial();    break;
            case 4: menuRegistrarPrestamo();    break;
            case 5: menuVerInfoMaterial();      break;
            case 6: menuConsultarPrestamo();    break;
            case 7:
                iConSesion = factory->getIControladorSesion();
                iConSesion->cerrarSesion();
                cout << "Sesion cerrada.\n";
                break;
            default: cout << "Opcion invalida.\n"; break;
        }
    }
}

// -----------------------------------------------------------------------
// Menú principal - para la interacción con el usuario 
// -----------------------------------------------------------------------
void menuPrincipal()
{
    factory = Factory::getInstancia();
    Usuario* user = Sesion::getInstance()->getUsuarioSesion();
    
    if (user == nullptr) return;

    if (user->getTipo() == "Funcionario")
    {
        menuFuncionario();
    }
    else if (user->getTipo() == "Lector")
    {
        menuLector();
    }
}

// -----------------------------------------------------------------------
// Menú para Autenticarse
// -----------------------------------------------------------------------
void menuAutenticacion()
{
    factory = Factory::getInstancia();
    int opcion = 0;

    while (opcion != 2)
    {
        cout << "\n=============================\n";
        cout << "   Sistema de Biblioteca\n";
        cout << "=============================\n";
        cout << "1. Iniciar Sesion\n";
        cout << "2. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1)
        {
            iConSesion = factory->getIControladorSesion();

            string numId, contrasenia;
            cout << "\n--- Iniciar Sesion ---\n";
            cout << "Numero de ID: ";
            getline(cin, numId);
            cout << "Contraseña: ";
            getline(cin, contrasenia);

            if (iConSesion->ingresarDatos(numId, contrasenia))
            {
                cout << "Inicio de sesion exitoso.\n";
                menuPrincipal();
            }
            else
            {
                cout << "Credenciales incorrectas. Intente nuevamente.\n";
            }
        }
        else if (opcion == 2)
        {
            cout << "Hasta luego.\n";
        }
        else
        {
            cout << "Opcion invalida.\n";
        }
    }
}