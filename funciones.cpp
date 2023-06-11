#include <iostream>
#include <random>
using namespace std;
#include "funciones.h"

string nombre_de_estatuilla(int numero_de_estat){
    // Devuelve el nombre de una de las estatuillas.

    string nombres_de_estat[5] =
    {"Estatuilla de arena: Cangrejo",
    "Estatuilla de tierra: Hormiga",
    "Estatuilla de agua: Medusa",
    "Estatuilla de aire: Aguila",
    "Estatuilla de fuego: Salamandra"};

    return nombres_de_estat[numero_de_estat];
}

void mostrar_inventario(string jugador1, string jugador2, int estatuillas[], int CANT_EST){
    // Muestra las estatuillas adquiridas por cada jugador hasta el momento.

    cout << "Inventario de " << jugador1 << ":" << endl;

    for(int i = 0; i < CANT_EST; i++){
        if(estatuillas[i] == 1){
            cout << "- " << nombre_de_estatuilla(i) << endl;
        }
    }

    cout << "Inventario de " << jugador2 << ":" << endl;

    for(int i = 0; i < CANT_EST; i++){
        if(estatuillas[i] == 2){
            cout << "- " << nombre_de_estatuilla(i) << endl;
        }
    }
}

void elegir_estatuilla(int estatuillas[], int CANT_EST){
    // Mostrar las estatuillas disponibles para elegir como objetivo durante fase de expedicion.

    cout << "Elegir estatuilla objetivo:" << endl;

    for(int i = 0; i < CANT_EST; i++){
        if(estatuillas[i] != 0){
            cout << i + 1 << " - " << nombre_de_estatuilla(i) << endl;
        }
    }
}

int tirar_dado(int cant_caras){
    // Devuelve un numero aleatorio con probabilidad 1/caras.

    int const MIN = 1;
    int const MAX = cant_caras;

    std::random_device rndm;
    std::mt19937 generator(rndm());
    std::uniform_int_distribution<int> distribution(MIN, MAX);

    return distribution(generator);
}

int jugador_inicial_exp(){
    // Determina el jugador que comienza la fase de expedicion.

    int jugador_inicial;
    int dado1 = 0;
    int dado2 = 0;

    while(dado1 == dado2){
        dado1 = tirar_dado(10);
        dado2 = tirar_dado(10);
    }

    if(dado1 < dado2){
        jugador_inicial = 1;
    } else{
        jugador_inicial = 2;
    }

    return jugador_inicial;
}

bool fin_expedicion(int estatuillas[], int CANT_EST){
    // Determina si se termina la fase de expedicion.

    bool fin = true;

    for(int i = 0; i < CANT_EST; i++){
        if(estatuillas[i] == 0){
            fin = false;
        }
    }

    return fin;
}

void fase_expedicion(string jugador1, string jugador2){
    // Jugar fase de expedicion.

    int const CANT_EST = 5;
    int estatuillas[CANT_EST] = {};
    int turno_de = jugador_inicial_exp();
    int objetivo1;
    int objetivo2;

    while(fin_expedicion(estatuillas, CANT_EST) == 0){
        mostrar_inventario(jugador1, jugador2, estatuillas, CANT_EST);
        elegir_estatuilla(estatuillas, CANT_EST);
        // Jugador 1 elige objetivo
        // Jugador 2 elige objetivo
        // Jugador 1 tira 2 dados
        // informar si gano y actualizar vector estatuillas()
        // Jugador 2 tira 2 dados
        // informar si gano y actualizar vector estatuillas()
    }
}

void menu_jugar(){
    // Opcion del menu.
    
    string jugador1;
    string jugador2;

    cout << "Ingrese nombre de jugador 1:" << endl;
    cin.ignore(); // Ignora el enter de cin >> entrada en menu();
    getline(cin, jugador1);

    cout << "Ingrese nombre de jugador 2:" << endl;
    getline(cin, jugador2);

    fase_expedicion(jugador1, jugador2);
}

void menu_estadisticas(){
    // Opcion del menu.
}

void menu_creditos(){
    // Opcion del menu.

    cout << "Irwin's Revenge es un juego creado por Gonzalo Ligero." << endl;
    cout << "Equipo de desarrolladores Algoritmos Anidados:" << endl;
    cout << "- Malvicino, Maximiliano (Legajo 28825)" << endl;
    cout << "- Serman, Guido (Legajo 28842)" << endl;

    menu();
}

void menu(){
    // Menu principal.

    int seleccion;
    cout << "-------------------------" << endl;
    cout << "IRWIN'S REVENGE" << endl;
    cout << "-------------------------" << endl;
    cout << "1 - JUGAR (DOS JUGADORES)" << endl;
    cout << "2 - ESTADISTICAS" << endl;
    cout << "3 - CREDITOS" << endl;
    cout << "-------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "-------------------------" << endl;

    do{
        cin >> seleccion;
    } while (seleccion < 0 || 3 < seleccion);

    switch(seleccion){
        case 0:
            break;
        case 1:
            menu_jugar();
            break;
        case 2:
            menu_estadisticas();
            break;
        case 3:
            menu_creditos();
            break;
    }
}