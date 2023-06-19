#include <iostream>
#include <random>
using namespace std;
#include "funciones.h"

void puntos_de_victoria(string nombres_jugadores[], int cant_jugs, int estatuillas[], int cant_ests, int ganador_fase_fin, int intentos[][5]){
    // Suma los puntos de victoria para determinar el ganador.

    int const CANT_JUGADORES = 2;
    int const CANT_ESTATUILLAS = cant_ests;
    int puntos_de_victoria[CANT_JUGADORES] = {}; // Array acumulador de puntos. Cada componente tiene los puntos de cada jugador.
    int const PDV_POR_ESTAT = 5;
    int const PDV_POR_EST_PP = 10;
    int const PDV_POR_GANADOR = 15;
    int const PDV_POR_GAN_PP = 50;
    int const PDV_POR_EST_RIVAL = 3;
    int const PDV_POR_LANZAM = 1;

    for(int i = 0; i < CANT_ESTATUILLAS; i++){ // OBTIENE ESTATUILLA
        puntos_de_victoria[estatuillas[i] - 1] += PDV_POR_ESTAT;
        cout << "El jugador " << estatuillas[i] << " gana " << PDV_POR_ESTAT << " puntos por haber obtenido la estatuilla " << nombre_de_estatuilla(i) << "." << endl;
    }

    for(int i = 0; i < CANT_JUGADORES; i++){ // OBTIENE ESTATUILLA EN PRIMER INTENTO
        for(int j = 0; j < CANT_ESTATUILLAS; j++){
            if(intentos[i][j] == 1 && estatuillas[j] == i + 1){
                puntos_de_victoria[i] += PDV_POR_EST_PP;
                cout << "El jugador " << i + 1 << " gana " << PDV_POR_EST_PP << " puntos por haber obtenido la estatuilla " << nombre_de_estatuilla(j) << " en el primer intento." << endl;
            }
        }
    }

    puntos_de_victoria[ganador_fase_fin - 1] += PDV_POR_GANADOR; // GANADOR FASE FINAL
    cout << "El jugador " << ganador_fase_fin << " gana " << PDV_POR_GANADOR << " puntos por haber ganado la fase final." << endl;

    for(int i = 0; i < CANT_JUGADORES; i++){ // GANADOR FASE FINAL SIN ESTATUILLAS
        bool gano_sin_ests = true;
        
        for(int j = 0; j < CANT_ESTATUILLAS; j++){
            if(ganador_fase_fin != i || estatuillas[j] == i){
                gano_sin_ests = false;
            }
        }

        if(gano_sin_ests == true){
            puntos_de_victoria[i] += PDV_POR_GAN_PP;
            cout << "El jugador " << i + 1 << " gana " << PDV_POR_GAN_PP << " puntos por haber ganado la fase final sin estatuillas en su inventario." << endl;
        }
    }

    for(int i = 0; i < CANT_JUGADORES; i++){ // RIVAL OBTIENE ESTATUILLA
        for(int j = 0; j < CANT_ESTATUILLAS; j++){
            if(estatuillas[j] != i + 1){
                puntos_de_victoria[i] -= PDV_POR_EST_RIVAL;
                cout << "El jugador " << i + 1 << " pierde " << PDV_POR_EST_RIVAL << " puntos por no haber ganado la " << nombre_de_estatuilla(j) << "." << endl;
            }
        }
    }

    for(int i = 0; i < CANT_JUGADORES; i++){ // LANZADOR FASE FINAL
        if(jugador_inicial_final(estatuillas, CANT_ESTATUILLAS, CANT_JUGADORES) == i + 1){
            puntos_de_victoria[i] -= PDV_POR_LANZAM;
            cout << "El jugador " << i + 1 << " pierde " << PDV_POR_LANZAM << " punto por haber lanzado en fase final." << endl;
        }
    }

    for(int i = 0; i < CANT_JUGADORES; i++){
        cout << "El jugador " << i + 1 << " obtuvo " << puntos_de_victoria[i] << " puntos de victoria." << endl;
    }
}

int jugador_inicial_final(int estatuillas[], int cant_ests, int cant_jugs){
    // Determina el jugador que comienza la fase de expedicion.

    int const CANT_ESTATUILLAS = cant_ests;
    int const CANT_JUGADORES = cant_jugs;

    int jugador_inicial = 1;
    int contador_ests = 0;

    for(int i = 0; i < CANT_ESTATUILLAS; i++){
        if(estatuillas[i] == jugador_inicial){
            contador_ests ++;
        }
    }

    if(contador_ests <= CANT_ESTATUILLAS / CANT_JUGADORES){
            jugador_inicial ++;
        }

    return jugador_inicial;
}

bool fin_de_fase_fin(int dados_final[], int cant_dds, int turno_actual, int portador_de_medusa, int portador_de_salamandra){
    // Determina si se termina la fase final.

    int const CANT_DADOS = cant_dds;
    int dados_ordenados[CANT_DADOS];

    for(int i = 0; i < CANT_DADOS; i++){ // Copiar vector de dados para ser ordenado
        dados_ordenados[i] = dados_final[i];
    }

    int aux;

    for(int i = 0; i < CANT_DADOS; i++){ // Ordenar de menor a mayor
        for(int j = 0; j < CANT_DADOS - 1; j++){
            if(dados_ordenados[j+1] < dados_ordenados[j]){
                aux = dados_ordenados[j+1];
                dados_ordenados[j+1] = dados_ordenados[j];
                dados_ordenados[j] = aux;
            }
        }
    }

    int vueltas_sin_dar = 0;

    if(turno_actual == portador_de_salamandra){ // Si tiene salamandra, mover el primer dado duplicado al final del array
        vueltas_sin_dar = 1;
        for(int i = 0; i < CANT_DADOS - 1; i++){
            if(dados_ordenados[i] == dados_ordenados[i+1]){
                for(int j = i; j < CANT_DADOS - i; j++){
                    dados_ordenados[j+1] = dados_ordenados[j+2];
                }
                dados_ordenados[CANT_DADOS-1] = dados_ordenados[i];
                i = CANT_DADOS - 1;
            }
        }
    }

    bool gana_por_escalera = true;
    bool gana_por_medusa = false;
    bool gana_fase_fin = false;

    for(int i = 0; i < CANT_DADOS - 1 - vueltas_sin_dar; i++){ // Gana por escalera (de 5 o de 4 segun vueltas_sin_dar sea 0 o 1)
        if(dados_ordenados[i] + 1 != dados_ordenados[i+1]){
            gana_por_escalera = false;
        }
    }

    if(turno_actual == portador_de_medusa){ // Gana por medusa
        gana_por_medusa = true;
        for(int i = 0; i < CANT_DADOS - 1; i++){
            if(dados_ordenados[i] != dados_ordenados[i+1]){
                gana_por_medusa = false;
            }
        }
    }

    if(gana_por_escalera == true){
        gana_fase_fin = true;
    } else if(gana_por_medusa == true){
        gana_fase_fin = true;
    }

    if(gana_fase_fin == true){
        cout << "El jugador " << turno_actual << " gana la fase final con los dados ";
        for(int i = 0; i < CANT_DADOS; i++){
            cout << dados_final[i];
            if(i < CANT_DADOS - 2){
                 cout << ", ";
            } else if(i < CANT_DADOS - 1){
                cout << " y ";
            } else{
                cout << "." << endl;
            }
        }
    }

    return gana_fase_fin;
}

void fase_final(string nombres_jugadores[], int cant_jugs, int estatuillas[], int cant_ests, int intentos[][5]){
    // Jugar fase final.

    int const CANT_ESTATUILLAS = cant_ests;
    int const CANT_JUGADORES = cant_jugs;

    int turno_actual = jugador_inicial_final(estatuillas, cant_ests, cant_jugs);
    int const CANT_DADOS = 5;
    int const CANT_CARAS_FINAL = 6;
    int dados_final[CANT_DADOS] = {};
    int ganador_fase_fin;
    bool primer_tiro_cangrejo = 0;
    int cambio_dado;
    int reemplazo_hormiga;
    cout << "El jugador " << estatuillas[1] << " tiene la estatuilla de la hormiga. Elegir un numero del 1 al 6 para luego usar como reemplazo." << endl;
    cin >> reemplazo_hormiga;

    cout << endl << "¡Comienza la fase final!" << endl;

    do{ // Tirar mientras no salga escalera
        cout << endl << "Turno de " << nombres_jugadores[turno_actual - 1] << endl;

        for(int i = 0; i < CANT_DADOS; i++){ // Cada jugador tira los dados
            dados_final[i] = tirar_dado(CANT_CARAS_FINAL);
            cout << "Tira " << dados_final[i] << endl;
        }

        if(turno_actual == estatuillas[1]){ // Si tiene hormiga, puede elegir un dado y cambiarlo por el reemplazo
            cout << "El jugador tiene la estatuilla de la hormiga. Elegir un dado para reemplazarlo por " << reemplazo_hormiga << ". ";
            cout << "Ingresar 0 en caso de no querer cambiar ningun dado." << endl;
            cin >> cambio_dado;

            if(cambio_dado != 0){
                for(int i = 0; i < CANT_DADOS; i++){
                    if(dados_final[i] == cambio_dado){
                        dados_final[i] = reemplazo_hormiga;
                        i = CANT_DADOS;
                    }
                }
            }
        }

        if(turno_actual == estatuillas[3]){ // Si tiene aguila, puede elegir un dado y asignarle un nuevo valor
            cout << "El jugador tiene la estatuilla del aguila. Elegir un dado para cambiar su valor. Ingresar 0 en caso de no querer cambiar ningun dado." << endl;
            cin >> cambio_dado;

            if(cambio_dado != 0){
                for(int i = 0; i < CANT_DADOS; i++){
                    if(dados_final[i] == cambio_dado){
                        cout << "ingresar nuevo valor para el dado " << dados_final[i] << ":" << endl;
                        cin >> dados_final[i];
                        i = CANT_DADOS;
                    }
                }
            }
        }

        ganador_fase_fin = turno_actual;

        if(primer_tiro_cangrejo == false && turno_actual == estatuillas[0] && fin_de_fase_fin(dados_final, CANT_DADOS, turno_actual, estatuillas[2], estatuillas[4]) == false){ // Si tiene cangrejo, no cambia el turno porque tira el jugador nuevamente
            primer_tiro_cangrejo = 1;
            cout << "El jugador " << turno_actual << " tira nuevamente por tener la estatuilla del cangrejo." << endl;
        } else{
            turno_actual = turno_nuevo(turno_actual, CANT_JUGADORES);
        }
    } while(fin_de_fase_fin(dados_final, CANT_DADOS, ganador_fase_fin, estatuillas[2], estatuillas[4]) == false);

    puntos_de_victoria(nombres_jugadores, CANT_JUGADORES, estatuillas, CANT_ESTATUILLAS, ganador_fase_fin, intentos);
}

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

bool guardar_inventario(int dado1, int dado2, int dado3, int turno_actual, int objetivos[]){
    // Guarda en el inventario de un jugador la estatuilla objetivo si los dados cumplen el requisito de obtencion.

    int const CANT_ESTATUILLAS = 5;

    bool ests_coinciden[CANT_ESTATUILLAS] = {
        arena_cangrejo(dado1, dado2, dado3),
        tierra_hormiga(dado1, dado2, dado3),
        agua_medusa(dado1, dado2, dado3),
        aire_aguila(dado1, dado2, dado3),
        fuego_salamandra(dado1, dado2, dado3)};

    int objetivo_elegido = objetivos[turno_actual - 1] - 1;
    int rtn = false;

    if(ests_coinciden[objetivo_elegido] == 1){
        rtn = true;
        cout << endl << "El jugador " << turno_actual << " gana la " << nombre_de_estatuilla(objetivo_elegido) << endl;
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

void mostrar_inventario(string nombres_jugadores[], int cant_jugs, int estatuillas[], int cant_ests){
    // Muestra las estatuillas adquiridas por cada jugador hasta el momento.

    int const CANT_JUGADORES = cant_jugs;
    int const CANT_ESTATUILLAS = cant_ests;

    cout << endl;

    for(int i = 0; i < CANT_JUGADORES; i++){
        cout << "Inventario de " << nombres_jugadores[i] << ":" << endl;

        for(int j = 0; j < CANT_ESTATUILLAS; j++){
            if(estatuillas[j] == i + 1){
                cout << "- " << nombre_de_estatuilla(j) << endl;
            }
        }
    }

    cout << endl;
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

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> aleatorio(1, cant_caras);

    return aleatorio(gen);
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

bool fin_de_fase_exp(int estatuillas[], int cant_ests){
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

void fase_expedicion(string nombres_jugadores[], int cant_jugs){
    // Jugar fase de expedicion.

    int const CANT_ESTATUILLAS = 5;
    int const CANT_JUGADORES = cant_jugs;
    int estatuillas[CANT_ESTATUILLAS] = {}; // Array que tiene en cada componente a quien pertenece la estatuilla o tiene cero si nadie la tiene
    int objetivos[CANT_JUGADORES]; // Array que tiene el objetivo de cada jugador por turno
    int turno_actual = jugador_inicial_exp(); // Numero de jugador al que le corresponde el turno (entero mayor que cero)
    int dado1;
    int dado2;
    int dado3;
    int const TIROS_MALDICION_AGUILA = 2;
    int const TURNOS_MALDICION_MEDUSA = 3;
    int turnos_perdidos = 0;

    int intentos[CANT_JUGADORES][CANT_ESTATUILLAS]; // Matriz que contiene las veces que un jugador eligio una estatuilla como objetivo. Cada fila representa un jugador. Cada columna representa una estatuilla.

    for(int i = 0; i < CANT_JUGADORES; i++){
        for(int j = 0; j < CANT_ESTATUILLAS; j++){
            intentos[i][j] = 0;
        }
    }

    cout << endl << "¡Comienza la fase de expedicion!" << endl;

    while(fin_de_fase_exp(estatuillas, CANT_ESTATUILLAS) == false){
        mostrar_inventario(nombres_jugadores, CANT_JUGADORES, estatuillas, CANT_ESTATUILLAS);

        for(int i = 0; i < CANT_JUGADORES; i++){ // CADA JUGADOR ELIGE OBJETIVO
            if(estatuillas[2] == turno_actual && turnos_perdidos < TURNOS_MALDICION_MEDUSA){ // Si el jugador tiene la medusa, no elige objetivo por 3 turnos
                cout << nombres_jugadores[turno_actual - 1] << " tiene la medusa y pierde los siguientes " << TURNOS_MALDICION_MEDUSA - turnos_perdidos << " turnos."  << endl;
            } else{
                cout << "Turno de " << nombres_jugadores[turno_actual - 1] << endl;
                elegir_estatuillas_disponibles(estatuillas, CANT_ESTATUILLAS);
                cin >> objetivos[turno_actual - 1];
                intentos[turno_actual - 1][objetivos[turno_actual - 1] - 1] ++; // Para contar puntos de victoria al final
            }

            turno_actual = turno_nuevo(turno_actual, CANT_JUGADORES);
        }

        for(int i = 0; i < CANT_JUGADORES; i++){ // CADA JUGADOR TIRA DADOS PARA CONSEGUIR ESTATUILLA OBJETIVO
            int objetivo_elegido = objetivos[turno_actual - 1] - 1;
            int tiros;

            cout << "Turno de " << nombres_jugadores[turno_actual - 1] << endl;

            if(estatuillas[2] == turno_actual && turnos_perdidos < TURNOS_MALDICION_MEDUSA){ // Si el jugador tiene la medusa, no tira por 3 turnos
                tiros = 0;
                turnos_perdidos ++;
            } else if(estatuillas[3] != 0 && estatuillas[3] != turno_actual){ // Si el rival tiene el aguila, tiene 2 tiros
                tiros = TIROS_MALDICION_AGUILA;
            } else{
                tiros = 1;
            }

            for(int i = 0; i < tiros; i++){ // Tiro de dados por jugador
                if(estatuillas[4] == 0 || estatuillas[4] == turno_actual){ // Si nadie tiene la salamandra o la tiene el del turno, este tira dos dados
                    dado1 = tirar_dado(10);
                    dado2 = tirar_dado(10);
                    cout << nombres_jugadores[turno_actual-1] << " tira los dados " << dado1 << " y " << dado2 << endl;
                    
                    if(estatuillas[objetivo_elegido] == 0 && guardar_inventario(dado1, dado2, 0, turno_actual, objetivos) == 1){
                        estatuillas[objetivo_elegido] = turno_actual;
                    }

                } else if(estatuillas[4] != 0 && estatuillas[4] != turno_actual){ // Si otro tiene la salamandra el del turno tira 3 dados
                    dado1 = tirar_dado(10);
                    dado2 = tirar_dado(10);
                    dado3 = tirar_dado(10);
                    cout << nombres_jugadores[turno_actual-1] << " tira los dados " << dado1 << ", " << dado2 << " y " << dado3 << endl;
                    
                    if(estatuillas[objetivo_elegido] == 0 && guardar_inventario(dado1, dado2, dado3, turno_actual, objetivos) == 1){
                        estatuillas[objetivo_elegido] = turno_actual;
                    }
                }
            }

            turno_actual = turno_nuevo(turno_actual, CANT_JUGADORES);
        }
    }

    fase_final(nombres_jugadores, CANT_JUGADORES, estatuillas, CANT_ESTATUILLAS, intentos);
}

void menu_jugar(int cant_jugs){
    // Opcion del menu.

    int const CANT_JUGADORES = cant_jugs;
    string nombres_jugadores[CANT_JUGADORES];

    cin.ignore(); // Ignora el enter de cin >> seleccion en menu();

    for(int i = 0; i < CANT_JUGADORES; i++){
        cout << "Ingrese nombre del jugador " << i + 1 << ":" << endl;
        getline(cin, nombres_jugadores[i]);
    }

    fase_expedicion(nombres_jugadores, CANT_JUGADORES);
}

void menu_estadisticas(){
    // Opcion del menu.
}

void menu_creditos(){
    // Opcion del menu.

    cout << "Irwin's Revenge es un juego creado por Gonzalo Ligero." << endl;
    cout << "El equipo de desarrolladores Algoritmos Anidados esta conformado por:" << endl;
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