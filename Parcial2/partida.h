#ifndef PARTIDA_H
#define PARTIDA_H
#include "juego.h"
#include <string>
using namespace std;

class Partida
{
private:
    Juego* juego;
    string fechayhora;


public:
    Partida();
    ~Partida();
    void initpartida();
    string reghorayfecha();
    string resultados();
    void setganador(string ganador);
};

#endif // PARTIDA_H
