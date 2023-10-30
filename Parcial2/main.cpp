#include <iostream>
#include <tablero.h>
#include <jugador.h>
#include <partida.h>

using namespace std;

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
    Jugador jugador1("Jugador1", '*');
    Jugador jugador2("Jugador2", '-');

    cout << "Jugadores:" << endl;
    cout << jugador1.getn() << " - Ficha: " << jugador1.getf() << endl;
    cout << jugador2.getn() << " - Ficha: " << jugador2.getf() << "\n" << endl;

    Partida partida("Jugador1", "Jugador2");
    partida.initpartida();

    Tablero tablero;
    tablero.startb();
    tablero.imprimir();

    return 0;
}
