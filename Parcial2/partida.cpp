#include "partida.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;
Partida::Partida()
{}


void Partida::initpartida(){

    cout << "\nPartida iniciada!" << endl;
    cout << reghorayfecha()<< endl;    
}


string Partida::reghorayfecha(){
    time_t tiempo = time(nullptr);
    struct tm* now = localtime(&tiempo);

    string fechayhora = to_string(now->tm_year + 1900) + '/' + (now->tm_mon +1 < 10 ? "0" : "") + to_string(now->tm_mon + 1) + '/' +
            (now->tm_mday < 10 ? "0" : "") + to_string(now->tm_mday) + ' ' +
            (now->tm_hour < 10 ? "0" : "") + to_string(now->tm_hour) + ':' +
            (now->tm_min < 10 ? "0" : "") + to_string(now->tm_min) + ':' +
            (now->tm_sec < 10 ? "0" : "") + to_string(now->tm_sec) + "\n";

    return fechayhora;
}


void Partida::sresultadop(string resultado) {
    this->resultadoPartida = resultado;
    historial.guardar(resultadoPartida);
}

string Partida::gresultadop() {
    return resultadoPartida;
}



