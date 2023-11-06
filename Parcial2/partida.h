#ifndef PARTIDA_H
#define PARTIDA_H
#include "historial.h"
#include <string>

using namespace std;

class Partida
{
private:
    string fechayhora;
    string resultadoPartida;
    Historial historial;


public:
    Partida();
    void initpartida();
    string reghorayfecha();
    void sresultadop(string resultadoPartida);
    string gresultadop();
    void setganador(string ganador);
    void guardarResultadoEnHistorial();
};

#endif // PARTIDA_H
