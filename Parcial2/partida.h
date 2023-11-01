#ifndef PARTIDA_H
#define PARTIDA_H
#include "jugador.h"
#include <string>
using namespace std;

class Partida
{
private:
    Jugador* jugador1;
    Jugador* jugador2;
    string ganador;
    int fichasganador;
    string fechayhora;
public:
    Partida(Jugador* jugador1, Jugador* jugador2);
    ~Partida();
    void initpartida();
    string reghorayfecha();
    void jganador(string ganador, int fichasganador);
    string resultados();
};

#endif // PARTIDA_H
