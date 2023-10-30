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

};

#endif // TABLERO_H
