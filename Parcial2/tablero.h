#ifndef TABLERO_H
#define TABLERO_H
#include <string>
using namespace std;

const int bsize = 4;

class Tablero
{
private:
    char tablero[bsize][bsize];
    int fichasj1 = 0;
    int fichasj2 = 0;


public:
    Tablero();
    void startb(char ficha1, char ficha2);
    void imprimir();
    bool movimientovalido(int fila, int columna, char ficha);
    bool movimiento(int fila, int columna, char ficha);
    bool ifmovalid(char ficha);
    void giro(int fila, int columna, char ficha);
    void cfichas(char ficha1, char ficha2);
    string ganadorp(string jug1, string jug2);

};

#endif // TABLERO_H
