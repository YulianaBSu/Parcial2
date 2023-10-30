#include <iostream>
#include <tablero.h>
#include <jugador.h>

using namespace std;



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
    Tablero tablero;
    tablero.startb();
    tablero.imprimir();
    Jugador jugador1("Jugador1", '*');
    Jugador jugador2("Jugador2", '-');

    cout << "\nJugadores:" << endl;
    cout << jugador1.getn() << " - Ficha: " << jugador1.getf() << endl;
    cout << jugador2.getn() << " - Ficha: " << jugador2.getf() << "\n" << endl;

    return 0;
}
