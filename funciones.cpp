#include <iostream>
#include <random>
using namespace std;
#include "funciones.h"

int turno_nuevo(int turno_actual){
    int turno_nuevo;
    int const CANT_JUGADORES = 2;

    if(turno_actual < CANT_JUGADORES){
        turno_nuevo = turno_actual + 1;
    } else{
        turno_nuevo = 1;
    }

    return turno_nuevo;
}

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

void mostrar_inventario(string jugadores_fase_exp[], int cant_jugs, int estatuillas[], int cant_ests){
    // Muestra las estatuillas adquiridas por cada jugador hasta el momento.

    int const CANT_JUGADORES = cant_jugs;
    int const CANT_ESTATUILLAS = cant_ests;

    for(int i = 0; i < CANT_JUGADORES; i++){
        cout << "Inventario de " << jugadores_fase_exp[i] << ":" << endl;

        for(int j = 0; j < CANT_ESTATUILLAS; j++){
            if(estatuillas[j] == 1){
                cout << "- " << nombre_de_estatuilla(j) << endl;
            }
        }
    }
}

void elegir_estatuilla(int estatuillas[], int CANT_ESTATUILLAS){
    // Mostrar las estatuillas disponibles para elegir como objetivo durante fase de expedicion.

    cout << "Elegir estatuilla objetivo:" << endl;

    for(int i = 0; i < CANT_ESTATUILLAS; i++){
        if(estatuillas[i] == 0){
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

bool fin_expedicion(int estatuillas[], int CANT_ESTATUILLAS){
    // Determina si se termina la fase de expedicion.

    bool fin = true;

    for(int i = 0; i < CANT_ESTATUILLAS; i++){
        if(estatuillas[i] == 0){
            fin = false;
        }
    }

    return fin;
}

void fase_expedicion(string jugadores_menu[], int cant_jugs){
    // Jugar fase de expedicion.

    int const CANT_ESTATUILLAS = 5;
    int estatuillas[CANT_ESTATUILLAS] = {};
    
    int const CANT_JUGADORES = cant_jugs;
    int objetivos[CANT_JUGADORES];
    string jugadores_fase_exp[CANT_JUGADORES];
    
    for(int i = 0; i < CANT_JUGADORES; i++){
        jugadores_fase_exp[i] = jugadores_menu[i];
    }

    int turno_actual = jugador_inicial_exp();

    while(fin_expedicion(estatuillas, CANT_ESTATUILLAS) == 0){
        mostrar_inventario(jugadores_fase_exp, CANT_JUGADORES, estatuillas, CANT_ESTATUILLAS);

        for(int i = 0; i < CANT_JUGADORES; i++){
            cout << "Turno de " << jugadores_fase_exp[turno_actual-1] << endl;
            elegir_estatuilla(estatuillas, CANT_ESTATUILLAS);
            cin >> objetivos[turno_actual-1];
            turno_actual = turno_nuevo(turno_actual);
        }


        // Jugador 1 tira 2 dados
        // informar si gano y actualizar vector estatuillas()
        // Jugador 2 tira 2 dados
        // informar si gano y actualizar vector estatuillas()
    }
}

void menu_jugar(int cant_jugs){
    // Opcion del menu.

    int const CANT_JUGADORES = cant_jugs;
    string jugadores_menu[CANT_JUGADORES];

    cin.ignore(); // Ignora el enter de cin >> seleccion en menu();

    for(int i = 0; i < CANT_JUGADORES; i++){
        cout << "Ingrese nombre del jugador " << i + 1 << ":" << endl;
        getline(cin, jugadores_menu[i]);
    }

    fase_expedicion(jugadores_menu, CANT_JUGADORES);
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
    cout << "-----------------------" << endl;
    cout << "IRWIN'S REVENGE" << endl;
    cout << "-----------------------" << endl;
    cout << "1 - JUGAR (2 JUGADORES)" << endl;
    cout << "2 - ESTADISTICAS" << endl;
    cout << "3 - CREDITOS" << endl;
    cout << "-----------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "-----------------------" << endl;

    do{
        cin >> seleccion;
    } while (seleccion < 0 || 3 < seleccion);

    int const CANT_JUGADORES = 2;

    switch(seleccion){
        case 0:
            break;
        case 1:
            menu_jugar(CANT_JUGADORES);
            break;
        case 2:
            menu_estadisticas();
            break;
        case 3:
            menu_creditos();
            break;
    }
}