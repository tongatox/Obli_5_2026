#include "menu.h"

#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include "../Reloj/Reloj.h"
#include "../interfaces/IControladorRegistrarUsuario.h"
#include "../interfaces/IControladorRegistrarMaterial.h"
#include "../interfaces/IControladorRegistrarPrestamo.h"
#include "../interfaces/IControladorVerInfoMaterial.h"
#include "../interfaces/IControladorSesion.h"
#include "../interfaces/IControladorConsultarPrestamo.h"
#include "../factory/Factory.h"
#include "../datatypes/Fecha.h"
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
Reloj *reloj;
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

    cout << "\n-- Datos ingresados --\n";
    cout << "ID        : " << numId << "\n";
    cout << "Nombre    : " << nombre << "\n";
    cout << "Num. Emp. : " << numEmp << "\n";
    cout << "\n1. Confirmar\n2. Cancelar\nOpcion: ";
    int op; cin >> op; cin.ignore();

    if (op == 1)
    {
        iConRegistrarUsuario->confirmarFuncionario();
        cout << "Funcionario registrado exitosamente.\n";
    }
    else
    {
        iConRegistrarUsuario->cancelarFuncionario();
        cout << "Registro de funcionario cancelado.\n";
    }
}

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

    cout << "\n-- Datos ingresados --\n";
    cout << "ID      : " << numId << "\n";
    cout << "Nombre  : " << nombre << "\n";
    cout << "Fecha   : " << dia << "/" << mes << "/" << anio << "\n";
    cout << "\n1. Confirmar\n2. Cancelar\nOpcion: ";
    int op; cin >> op; cin.ignore();

    if (op == 1)
    {
        iConRegistrarUsuario->confirmarLector();
        cout << "Lector registrado exitosamente.\n";
    }
    else
    {
        iConRegistrarUsuario->cancelarLector();
        cout << "Registro de lector cancelado.\n";
    }
}

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
        cout << "Autor: ";              getline(cin, autor);
        cout << "Cantidad de paginas: "; cin >> cantPag; cin.ignore();

        iConRegistrarMaterial->registrarLibro(codigo, titulo, anio, autor, cantPag);

        cout << "\n-- Datos del Libro --\n";
        cout << "Codigo  : " << codigo << "\n";
        cout << "Titulo  : " << titulo << "\n";
        cout << "Anio    : " << anio << "\n";
        cout << "Autor   : " << autor << "\n";
        cout << "Paginas : " << cantPag << "\n";
        cout << "\n1. Confirmar\n2. Cancelar\nOpcion: ";
        int op; cin >> op; cin.ignore();

        if (op == 1)
        {
            iConRegistrarMaterial->confirmarLibro();
            cout << "Libro registrado exitosamente.\n";
        }
        else
        {
            iConRegistrarMaterial->cancelarLibro();
            cout << "Registro de libro cancelado.\n";
        }
    }
    else if (opcion == 2)
    {
        int numEdi;
        char mensual;
        cout << "Numero de edicion: "; cin >> numEdi; cin.ignore();
        cout << "Es mensual? (s/n): "; cin >> mensual; cin.ignore();
        bool esMensual = (mensual == 's' || mensual == 'S');

        iConRegistrarMaterial->registrarRevista(codigo, titulo, anio, numEdi, esMensual);

        cout << "\n-- Datos de la Revista --\n";
        cout << "Codigo  : " << codigo << "\n";
        cout << "Titulo  : " << titulo << "\n";
        cout << "Anio    : " << anio << "\n";
        cout << "Edicion : " << numEdi << "\n";
        cout << "Mensual : " << (esMensual ? "Si" : "No") << "\n";
        cout << "\n1. Confirmar\n2. Cancelar\nOpcion: ";
        int op; cin >> op; cin.ignore();

        if (op == 1)
        {
            iConRegistrarMaterial->confirmarRevista();
            cout << "Revista registrada exitosamente.\n";
        }
        else
        {
            iConRegistrarMaterial->cancelarRevista();
            cout << "Registro de revista cancelado.\n";
        }
    }
    else
    {
        cout << "Opcion invalida. Operacion cancelada.\n";
    }
}

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

    cout << "\n-- Datos del Prestamo --\n";
    cout << "Lector   : " << numId << "\n";
    cout << "Material : " << codigoMat << "\n";
    cout << "Fecha    : " << dia << "/" << mes << "/" << anio << "\n";
    cout << "Dias     : " << diasPermi << "\n";
    cout << "\n1. Confirmar\n2. Cancelar\nOpcion: ";
    int op; cin >> op; cin.ignore();

    if (op == 1)
    {
        iConRegistrarPrestamo->confirmarPrestamo();
        cout << "Prestamo registrado exitosamente.\n";
    }
    else
    {
        iConRegistrarPrestamo->cancelarPrestamo();
        cout << "Registro de prestamo cancelado.\n";
    }
}

static void menuVerInfoMaterial()
{
    iConVerInfoMaterial = factory->getIControladorVerInfoMaterial();
    map<string, Material*> todos = iConVerInfoMaterial->consultarListaMaterial();

    if (todos.empty())
    {
        cout << "No hay materiales registrados.\n";
        return;
    }

    cout << "\nMateriales disponibles\n";
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

    cout << "\nDetalle del Material\n";
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

static void menuConsultarPrestamo()
{
    iConConsultarPrestamo = factory->getIControladorConsultarPrestamo();
    map<int, Prestamo*> prestamos = iConConsultarPrestamo->consultarPrestamos();

    if (prestamos.empty())
    {
        cout << "No hay prestamos registrados.\n";
        return;
    }

    cout << "\nPrestamos registrados\n";
    for (auto const& x : prestamos)
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

static void menuConsultarMisPrestamos()
{
    Usuario* u = Sesion::getInstance()->getUsuarioSesion();
    Lector* l = dynamic_cast<Lector*>(u);
    if (l == nullptr) return;

    Prestamo** prestamos = l->getPrestamo();
    bool hayPrestamos = false;

    cout << "\nMis Prestamos\n";
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
            cout << " | " << p->getMaterial()->getTipo() <<": " << p->getMaterial()->getTitulo();
        cout << "\n";
    }

    if (!hayPrestamos)
        cout << "No tiene prestamos registrados.\n";

    delete[] prestamos;
}

static void menuLector()
{
    int opcion = 0;
    while (opcion != 4)
    {
        cout << "\nMenu Lector\n";
        cout << "1. Ver Informacion Material\n";
        cout << "2. Consultar mis Prestamos\n";
        cout << "3. Consultar Fecha y Hora Actual\n";
        cout << "4. Cerrar Sesion\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
            case 1: menuVerInfoMaterial();     break;
            case 2: menuConsultarMisPrestamos(); break;
            case 3: 
                reloj = Reloj::getInstance();
                reloj->getFechaHoraActual();
                break;
            case 4:
                iConSesion = factory->getIControladorSesion();
                iConSesion->cerrarSesion();
                cout << "Sesion cerrada.\n";
                break;
            default: cout << "Opcion invalida.\n"; break;
        }
    }
}

static void menuFuncionario()
{
    int opcion = 0;
    while (opcion != 8)
    {
        cout << "\nMenu Funcionario\n";
        cout << "1. Registrar Funcionario\n";
        cout << "2. Registrar Lector\n";
        cout << "3. Registrar Material\n";
        cout << "4. Registrar Prestamo\n";
        cout << "5. Ver Informacion Material\n";
        cout << "6. Consultar Prestamos\n";
        cout << "7. Consultar Fecha y Hora Actual\n";
        cout << "8. Cerrar Sesion\n";
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
                reloj = Reloj::getInstance();
                reloj->getFechaHoraActual();
                break;
            case 8:
                iConSesion = factory->getIControladorSesion();
                iConSesion->cerrarSesion();
                cout << "Sesion cerrada.\n";
                break;
            default: cout << "Opcion invalida.\n"; break;
        }
    }
}

void menuPrincipal()
{
    factory = Factory::getInstancia();
    Usuario* user = Sesion::getInstance()->getUsuarioSesion();
    
    if (user == nullptr) return;

    // muestra el menu correspondiente al tipo de usuario
    if (user->getTipo() == "Funcionario")
    {
        menuFuncionario();
    }
    else if (user->getTipo() == "Lector")
    {
        menuLector();
    }
}

void menuAutenticacion()
{
    factory = Factory::getInstancia();
    int opcion = 0;

    while (opcion != 2)
    {
        cout << "\nSistema de Biblioteca\n";
        cout << "1. Iniciar Sesion\n";
        cout << "2. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1)
        {
            iConSesion = factory->getIControladorSesion();

            string numId, contrasenia;
            cout << "\nIniciar Sesion\n";
            cout << "Numero de ID: ";
            getline(cin, numId);
            cout << "Contraseña: ";
            getline(cin, contrasenia);

            if (iConSesion->ingresarDatos(numId, contrasenia))
            {
                Usuario* user = Sesion::getInstance()->getUsuarioSesion();
                cout << "Bienvenido, "
                     << user->getNombre() << " (" << user->getTipo() << ").\n";
                menuPrincipal();
            }
            else
            {
                cout << "Datos incorrectos. Intente nuevamente.\n";
            }
        }
        else if (opcion == 2)
        {
            cout << "Chauuu!!.\n";
        }
        else
        {
            cout << "Opcion invalida.\n";
        }
    }
}