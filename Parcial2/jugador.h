#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>

using namespace std;

class Jugador
{
private:
    string nombre;
    char ficha;

public:
    Jugador(string nombre, char ficha);
    string getn();
    char getf();
};

#endif // JUGADOR_H
