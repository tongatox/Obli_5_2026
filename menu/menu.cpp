#include "menu.h"

#include <iostream>
#include <string>
#include <map>
#include "../interfaces/controllers/IControladorRegistrarUsuario.h"
#include "../interfaces/controllers/IControladorRegistrarMaterial.h"
#include "../interfaces/controllers/IControladorRegistrarPrestamo.h"
#include "../interfaces/controllers/IControladorVerInfoMaterial.h"
#include "../factory/Factory.h"
#include "../datatypes/Fecha.h"
#include "../collections/UsuarioCollection.h"
#include "../entities/Lector.h"
#include "../entities/Funcionario.h"
#include "../entities/Libro.h"
#include "../entities/Revista.h"

using namespace std;

Factory *factory;
IControladorRegistrarUsuario *iConRegistrarUsuario;
IControladorRegistrarMaterial *iConRegistrarMaterial;
IControladorRegistrarPrestamo *iConRegistrarPrestamo;
IControladorVerInfoMaterial *iConVerInfoMaterial;

// -----------------------------------------------------------------------
// Submenú: Para realizar el registro de un usuario - lector o funcionario
// -----------------------------------------------------------------------
static void menuRegistrarUsuario()
{
    iConRegistrarUsuario = factory->getIControladorRegistrarUsuario();
    int opcion;

    cout << "\n--- Registrar Usuario ---\n";
    cout << "1. Lector\n";
    cout << "2. Funcionario\n";
    cout << "Opcion: ";
    cin >> opcion;
    cin.ignore();

    string numId, nombre, contrasenia;
    cout << "Numero de ID: ";   getline(cin, numId);
    cout << "Nombre: ";         getline(cin, nombre);
    cout << "Contraseña: ";     getline(cin, contrasenia);

    if (opcion == 1)
    {
        int dia, mes, anio;
        cout << "Fecha de registro (dd mm aaaa): ";
        cin >> dia >> mes >> anio;
        cin.ignore();

        iConRegistrarUsuario->registrarLector(numId, nombre, contrasenia, Fecha(dia, mes, anio));
        iConRegistrarUsuario->confirmarLector();
        cout << "Lector registrado.\n";
    }
    else if (opcion == 2)
    {
        int numEmp;
        cout << "Numero de empleado: ";
        cin >> numEmp;
        cin.ignore();

        iConRegistrarUsuario->registrarFuncionario(numId, nombre, contrasenia, numEmp);
        iConRegistrarUsuario->confirmarFuncionario();
        cout << "Funcionario registrado.\n";
    }
    else
    {
        cout << "Opcion invalida. Operacion cancelada.\n";
    }
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

    cout << "Numero de ID del Lector: ";    cin.ignore(); getline(cin, numId);
    cout << "Codigo del Material: ";        getline(cin, codigoMat);
    cout << "Fecha del prestamo (dd mm aaaa): ";
    cin >> dia >> mes >> anio;
    cout << "Dias permitidos: ";
    cin >> diasPermi;
    cin.ignore();

    iConRegistrarPrestamo->registrarPrestamo(Fecha(dia, mes, anio), diasPermi, numId, codigoMat);
    iConRegistrarPrestamo->confirmarPrestamo();
    cout << "Prestamo registrado.\n";
}

// -----------------------`------------------------------------------------
// Submenú: Listado de usuarios y materiales registrados
// -----------------------------------------------------------------------
static void menuListar()
{
    // Implementar el menuListar
}

// -----------------------------------------------------------------------
// Menú principal - para la interacción con el usuario 
// -----------------------------------------------------------------------
void menuPrincipal()
{
    factory = Factory::getInstancia();
    int opcion = 0;

    while (opcion != 5)
    {
        cout << "\n=============================\n";
        cout << "   Sistema de Biblioteca\n";
        cout << "=============================\n";
        cout << "1. Registrar Usuario\n";
        cout << "2. Registrar Material\n";
        cout << "3. Registrar Prestamo\n";
        cout << "4. Listar\n";
        cout << "5. Salir y cerrar sesión\n"; // Se cierra la sesión y luego el programa termina
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1: menuRegistrarUsuario();  break;
            case 2: menuRegistrarMaterial(); break;
            case 3: menuRegistrarPrestamo(); break;
            case 4: menuListar();            break;
            case 5: cout << "Hasta luego.\n"; break;
            default: cout << "Opcion invalida.\n"; break;
        }
    }
}

// -----------------------------------------------------------------------
// Menú para el inicio de sesión del usuario, sera el menuAutenticacion solicitando los datos 
// -----------------------------------------------------------------------`