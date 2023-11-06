#ifndef PARTIDA_H
#define PARTIDA_H
#include <string>
using namespace std;

class Partida
{
private:
    string fechayhora;
    string resultadoPartida;


public:
    Partida();
    ~Partida();
    void initpartida();
    string reghorayfecha();
    void sresultadop(string resultadoPartida);
    string gresultadop();
    void setganador(string ganador);
};

#endif // PARTIDA_H
