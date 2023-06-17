#include <iostream>
using namespace std;
#include "funciones.h"

int main(){
    //menu();
    int arr[5] = {2,4,6,3,1};
    cout << fin_de_fase_fin(arr, 5, 1, 2, 1)<<endl;
}

/*
COMPILAR Y CORRER PRUEBA DE ESCRITORIO:
g++ -o ./bin/main main.cpp funciones.cpp
./bin/main < ./bin/test.txt

COMPILAR Y EJECUTAR:
g++ -o ./bin/main main.cpp funciones.cpp
./bin/main
*/