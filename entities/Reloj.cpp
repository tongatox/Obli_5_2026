#include "Reloj.h"
#include <iostream>
#include <ctime>

using namespace std;

Reloj* Reloj::instance = nullptr;

Reloj* Reloj::getInstance()
{
    if (instance == nullptr)
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        instance = new Reloj(ltm->tm_hour, ltm->tm_min, ltm->tm_sec, ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
    }
    return instance;
}


Reloj::Reloj(int horas, int minutos, int segundos, int dia, int mes, int anio)
{
    this->horas = horas;
    this->minutos = minutos;
    this->segundos = segundos;
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int Reloj::getHoras() { return horas; }
int Reloj::getMinutos() { return minutos; }
int Reloj::getSegundos() { return segundos; }
int Reloj::getDia() { return dia; }
int Reloj::getMes() { return mes; }
int Reloj::getAnio() { return anio; }

void Reloj::setHoras(int horas) { this->horas = horas; }
void Reloj::setMinutos(int minutos) { this->minutos = minutos; }
void Reloj::setSegundos(int segundos) { this->segundos = segundos; }
void Reloj::setDia(int dia) { this->dia = dia; }
void Reloj::setMes(int mes) { this->mes = mes; }
void Reloj::setAnio(int anio) { this->anio = anio; }

Reloj::~Reloj() {}


void Reloj::getFechaHoraActual()
{
   cout << "[" << this->dia << "/" << this->mes << "/" << this->anio << "  "
        << this->horas << ":" << this->minutos << ":" << this->segundos << "]";
    system("sleep 1");
}