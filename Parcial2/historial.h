#ifndef HISTORIAL_H
#define HISTORIAL_H
#include "partida.h"

class Historial
{
private:
    Partida* partidasn;
    int partidas;

public:
    Historial();
    void agregar();
    void guardar();
    void cargar();
    void imprimir();

};

#endif // HISTORIAL_H
