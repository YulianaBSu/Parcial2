#ifndef TABLERO_H
#define TABLERO_H

const int bsize = 8;

class Tablero
{
private:
    char tablero[bsize][bsize];

public:
    Tablero();
    void startb();
    void imprimir();
    bool movimiento(int fila, int columna, char ficha);

};

#endif // TABLERO_H
