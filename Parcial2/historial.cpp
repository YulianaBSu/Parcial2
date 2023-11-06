#include "historial.h"
#include <fstream>
#include <iostream>
using namespace std;

Historial::Historial()
{

}
void Historial::guardar(const string& resultado) {
    ofstream archivo("historial.txt", ios::app);
    if (archivo.is_open()) {
        archivo << resultado << endl;
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo de historial." << endl;
    }
}


void Historial::imprimir() {
    ifstream archivo("historial.txt");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo de historial." << endl;
    }
}
