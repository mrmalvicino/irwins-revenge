#include <iostream>
#include <random>
using namespace std;
#include "funciones.h"

bool arena_cangrejo(int dado1, int dado2, int dado3){
    // Determina si los dados tirados cumplen los requisitos para obtener la estatuilla.

    bool rtn = true;

    if( (dado1 % 2 == 0 && dado2 % 2 == 0 && dado3 % 2 == 0 && 0 < dado3) || (dado1 % 2 != 0 && dado2 % 2 != 0 && dado3 % 2 != 0 && 0 < dado3) ){
        rtn = false;
    }

    return rtn;
}

bool tierra_hormiga(int dado1, int dado2, int dado3){
    // Determina si los dados tirados cumplen los requisitos para obtener la estatuilla.

    bool rtn = false;

    if( (dado1 < 5 && dado2 < 5) || (dado2 < 5 && dado3 < 5 && 0 < dado3) || (dado1 < 5 && dado3 < 5 && 0 < dado3) ){
        rtn = true;
    }

    return rtn;
}

bool agua_medusa(int dado1, int dado2, int dado3){
    // Determina si los dados tirados cumplen los requisitos para obtener la estatuilla.

    bool rtn = false;

    if( (dado1 + dado2 == 7) || ((dado2 + dado3 == 7) && 0 < dado3) || ((dado1 + dado3 == 7) && 0 < dado3) ){
        rtn = true;
    }

    return rtn;
}

bool aire_aguila(int dado1, int dado2, int dado3){
    // Determina si los dados tirados cumplen los requisitos para obtener la estatuilla.

    bool rtn = false;
    
    if( (dado1 == 1 && dado2 == 10) || (dado1 == 10 && dado2 == 1) || (dado2 == 1 && dado3 == 10) || (dado2 == 10 && dado3 == 1) || (dado1 == 1 && dado3 == 10) || (dado1 == 10 && dado3 == 1) ){
        rtn = true;
    }

    return rtn;
}

bool fuego_salamandra(int dado1, int dado2, int dado3){
    // Determina si los dados tirados cumplen los requisitos para obtener la estatuilla.

    bool rtn = false;
    
    if( dado1 == dado2 + 1 || dado2 == dado1 + 1 || ((dado2 == dado3 + 1) && 0 < dado3) || ((dado3 == dado2 + 1) && 0 < dado3) || ((dado1 == dado3 + 1) && 0 < dado3) || ((dado3 == dado1 + 1) && 0 < dado3) ){
        rtn = true;
    }

    return rtn;
}

int turno_nuevo(int turno_actual, int cant_jugs){
    int turno_nuevo;
    int const CANT_JUGADORES = cant_jugs;

    if(turno_actual < CANT_JUGADORES){
        turno_nuevo = turno_actual + 1;
    } else{
        turno_nuevo = 1;
    }

    return turno_nuevo;
}

string nombre_de_estatuilla(int numero_de_estat){
    // Devuelve el nombre de una de las estatuillas.

    int const CANT_ESTATUILLAS = 5;
    string nombres_de_estat[CANT_ESTATUILLAS] =
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
            if(estatuillas[j] == i + 1){
                cout << "- " << nombre_de_estatuilla(j) << endl;
            }
        }
    }
}

void elegir_estatuillas_disponibles(int estatuillas[], int cant_ests){
    // Mostrar las estatuillas disponibles para elegir como objetivo durante fase de expedicion.

    int CANT_ESTATUILLAS = cant_ests;

    cout << "Elegir estatuilla objetivo:" << endl;

    for(int i = 0; i < CANT_ESTATUILLAS; i++){
        if(estatuillas[i] == 0){
            cout << i + 1 << " - " << nombre_de_estatuilla(i) << endl;
        }
    }
}

int tirar_dado(int cant_caras){
    // Devuelve un numero aleatorio con probabilidad 1/caras.

    int const CANT_CARAS = cant_caras;
    int numeros[CANT_CARAS];

    for(int i = 0; i < CANT_CARAS; i++){
      numeros[i] = i + 1;
    }

    int indice = rand() % 10;
    int aleatorio = numeros[indice];

    return aleatorio;
}

int jugador_inicial_exp(){
    // Determina el jugador que comienza la fase de expedicion.

    int jugador_inicial;
    int dado_jugador_1 = 0;
    int dado_jugador_2 = 0;

    while(dado_jugador_1 == dado_jugador_2){
        dado_jugador_1 = tirar_dado(10);
        dado_jugador_2 = tirar_dado(10);
    }

    if(dado_jugador_1 < dado_jugador_2){
        jugador_inicial = 1;
    } else{
        jugador_inicial = 2;
    }

    return jugador_inicial;
}

bool fin_expedicion(int estatuillas[], int cant_ests){
    // Determina si se termina la fase de expedicion.

    int CANT_ESTATUILLAS = cant_ests;
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
    int estatuillas[CANT_ESTATUILLAS] = {0,0,0,0,0}; // Array que tiene en cada componente a quien pertenece la estatuilla o tiene cero si nadie la tiene
    
    int const CANT_JUGADORES = cant_jugs;
    int objetivos[CANT_JUGADORES];
    string jugadores_fase_exp[CANT_JUGADORES];
    
    for(int i = 0; i < CANT_JUGADORES; i++){
        jugadores_fase_exp[i] = jugadores_menu[i];
    }

    int turno_actual = jugador_inicial_exp();
    int dado1;
    int dado2;
    int dado3;

    while(fin_expedicion(estatuillas, CANT_ESTATUILLAS) == 0){
        mostrar_inventario(jugadores_fase_exp, CANT_JUGADORES, estatuillas, CANT_ESTATUILLAS);

        for(int i = 0; i < CANT_JUGADORES; i++){ // Jugadores eligen objetivos
            cout << "Turno de " << jugadores_fase_exp[turno_actual - 1] << endl;
            elegir_estatuillas_disponibles(estatuillas, CANT_ESTATUILLAS);
            cin >> objetivos[turno_actual - 1];
            turno_actual = turno_nuevo(turno_actual, CANT_JUGADORES);
        }

        for(int i = 0; i < CANT_JUGADORES; i++){ // Jugadores tiran dados para conseguir estatuillas objetivo
            cout << "Turno de " << jugadores_fase_exp[turno_actual - 1] << endl;
            
            if(estatuillas[4] == 0 || estatuillas[4] == turno_actual){ // Si nadie tiene la salamandra o la tiene el del turno, este tira dos dados
                dado1 = tirar_dado(10);
                dado2 = tirar_dado(10);
                cout << jugadores_fase_exp[turno_actual-1] << " tiro los dados " << dado1 << " y " << dado2 << endl;
                
                bool ests_coinciden[CANT_ESTATUILLAS] = {
                arena_cangrejo(dado1, dado2, 0),
                tierra_hormiga(dado1, dado2, 0),
                agua_medusa(dado1, dado2, 0),
                aire_aguila(dado1, dado2, 0),
                fuego_salamandra(dado1, dado2, 0)};

                int objetivo_elegido = objetivos[turno_actual - 1];

                if(ests_coinciden[objetivo_elegido] == 1){
                    estatuillas[objetivo_elegido] = turno_actual;
                    cout << "El jugador " << turno_actual << " gana la estatuilla " << nombre_de_estatuilla(objetivo_elegido) << endl;
                }

            } else if(estatuillas[4] != 0 && estatuillas[4] != turno_actual){ // Si otro tiene la salamandra el del turno tira 3 dados
                dado1 = tirar_dado(10);
                dado2 = tirar_dado(10);
                dado3 = tirar_dado(10);
                cout << jugadores_fase_exp[turno_actual-1] << " tiro los dados " << dado1 << ", " << dado2 << " y " << dado3 << endl;

                bool ests_coinciden[CANT_ESTATUILLAS] = {
                arena_cangrejo(dado1, dado2, dado3),
                tierra_hormiga(dado1, dado2, dado3),
                agua_medusa(dado1, dado2, dado3),
                aire_aguila(dado1, dado2, dado3),
                fuego_salamandra(dado1, dado2, dado3)};

                int objetivo_elegido = objetivos[turno_actual - 1];

                if(ests_coinciden[objetivo_elegido] == 1){
                    estatuillas[objetivo_elegido] = turno_actual;
                    cout << "El jugador " << turno_actual << " gana la estatuilla " << nombre_de_estatuilla(objetivo_elegido) << endl;
                }
            }

            turno_actual = turno_nuevo(turno_actual, CANT_JUGADORES);
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