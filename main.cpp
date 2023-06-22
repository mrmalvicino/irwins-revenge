#include <iostream>
using namespace std;
#include "funciones.h"

int main(){
    int max_pdv = 0;
    string max_jugador = "No se registran partidas";

    limpiar_terminal();
    menu(max_pdv, max_jugador);
}

/*
COMPILAR Y CORRER PRUEBA DE ESCRITORIO:
g++ -o ./bin/main main.cpp funciones.cpp
./bin/main < ./bin/test.txt

COMPILAR Y EJECUTAR:
g++ -o ./bin/main main.cpp funciones.cpp
./bin/main
*/