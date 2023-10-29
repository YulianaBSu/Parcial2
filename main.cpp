#include <iostream>
#include <ctime>
using namespace std;

const int bsize = 8;

class Tablero {
private:
    char tablero[bsize][bsize];
public:
    Tablero();
    void startb(){

    }

    void imprimir(){

    }

    bool movimientoval();

    void movimiento(){

    }

    void giro(){
    }

};

class Jugador {
private:
    string nombre;
    char ficha;

public:
    Jugador();

    string getn() {
        return nombre;
    }

    char getf() {
        return ficha;
    }
};

class Partida {
private:
    string jugador1;
    string jugador2;
    string ganador;
    int fichasganador;
    string fecha;
    string hora;

public:
    Partida();

    void initpartida() {

    }
    void reghorayfecha() {

    }


};

class Historial {
private:
    int partidas;

public:
    void agregar(){
    }

    void guardar(){
    }

    void cargar(){

    }

    void imprimir(){

    }

};

class Juego {
private:
    Jugador jugador1;
    Jugador jugador2;
    Tablero tablero;
    Historial historial;

public:
    Juego();

    void start(){
    }

    void partida(){
    }

    void turno(){
    }
    void finpartida(){
    }

};


int main()

{
    return 0;
}
