#ifndef PARTIDA_H
#define PARTIDA_H
#include <string>
using namespace std;

class Partida
{
private:
    string jugador1;
    string jugador2;
    string ganador;
    int fichasganador;
    string fecha;
    string hora;

public:
    Partida(string jugador1, string jugador2);
    void initpartida();
    void reghorayfecha();
    void jganador(string ganador, int fichas);
};

#endif // PARTIDA_H
