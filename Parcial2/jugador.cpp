#include "jugador.h"

Jugador::Jugador(string nombre, char ficha) : nombre(nombre), ficha(ficha)
{

}

string Jugador::getn(){
    return nombre;
}

char Jugador::getf(){
    return ficha;
}
