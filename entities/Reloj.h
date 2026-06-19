#ifndef RELOJ
#define RELOJ

class Reloj
{
private:
    static Reloj *instance;
    int horas;
    int minutos;
    int segundos;
    int dia;
    int mes;
    int anio;
    Reloj(int horas, int minutos, int segundos, int dia, int mes, int anio);
public:
    static Reloj* getInstance();
    int getHoras();
    int getMinutos();
    int getSegundos();
    int getDia();
    int getMes();
    int getAnio();
    void setHoras(int horas);
    void setMinutos(int minutos);
    void setSegundos(int segundos);
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    ~Reloj();

    void getFechaHoraActual();

};




#endif