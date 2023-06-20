#include <iostream>
using namespace std;
#include "funciones.h"

int main(){
    system("clear");
    //menu();

    cout << "Tira 5 dados:" << endl;
    dibujar_dado(9, 0);
    dibujar_dado(4, 1);
    dibujar_dado(3, 2);
    dibujar_dado(2, 3);
    dibujar_dado(1, 4);
}

/*
COMPILAR Y CORRER PRUEBA DE ESCRITORIO:
g++ -o ./bin/main main.cpp funciones.cpp
./bin/main < ./bin/test.txt

COMPILAR Y EJECUTAR:
g++ -o ./bin/main main.cpp funciones.cpp
./bin/main
*/