#include <iostream>
using namespace std;

int tirar_dado(int caras){
    // Devuelve un numero aleatorio con probabilidad 1/caras.
    int aleatorio;

    return aleatorio;
}

int jugador_inicial_exp(){
    // Determina que jugador comienza la fase de expedicion.
    int jugador_inicial;
    
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

void menu_jugar(){
    // Opcion del menu.
    string jugador1;
    string jugador2;

    cout << "Ingrese nombre de jugador 1:" << endl;
    cin.ignore(); // Ignora el enter de cin >> entrada en menu();
    getline(cin, jugador1);

    cout << "Ingrese nombre de jugador 2:" << endl;
    getline(cin, jugador2);
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
}

void menu(){
    // Menu principal.
    int entrada;
    cout << "IRWIN'S REVENGE" << endl;
    cout << "---------------" << endl;
    cout << "1 - JUGAR (DOS JUGADORES)" << endl;
    cout << "2 - ESTADISTICAS" << endl;
    cout << "3 - CREDITOS" << endl;
    cout << "---------------" << endl;
    cout << "0 - SALIR" << endl;

    cin >> entrada;

    switch(entrada){
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