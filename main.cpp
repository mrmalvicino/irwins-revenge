#include <iostream>
using namespace std;
#include "funciones.h"

int main(){
    menu();

    int const CANT_EST = 5;
    int estatuillas[CANT_EST] = {1,1,1,1,1};
    int turno_de = jugador_inicial_exp();
    int objetivo1;
    int objetivo2;

    while(fin_expedicion(estatuillas, CANT_EST) == 0){

    }
}

/*
g++ -o ./bin/main main.cpp funciones.cpp
./bin/main < ./bin/test.txt
*/