#include <iostream>
#include <random>
using namespace std;
#include "funciones.h"

void puntos_de_victoria(string nombres_jugadores[], int const CANT_JUGADORES, int estatuillas[], int const CANT_ESTATUILLAS, int ganador_fase_fin, int intentos[][5]){
    // Suma los puntos de victoria para determinar el ganador.

    int const PDV_POR_ESTAT = 5;
    int const PDV_POR_EST_PP = 10;
    int const PDV_POR_GANADOR = 15;
    int const PDV_POR_GAN_PP = 50;
    int const PDV_POR_EST_RIVAL = 3;
    int const PDV_POR_LANZAM = 1;
    int puntos_de_victoria[CANT_JUGADORES]; // Array acumulador de puntos. Cada componente tiene los puntos de cada jugador.

    for(int i = 0; i < CANT_JUGADORES; i++){
        puntos_de_victoria[i] = 0;
    }

    for(int i = 0; i < CANT_ESTATUILLAS; i++){ // OBTIENE ESTATUILLA
        puntos_de_victoria[estatuillas[i] - 1] += PDV_POR_ESTAT;
        cout << "El jugador " << estatuillas[i] << " gana " << PDV_POR_ESTAT << " puntos por haber obtenido la estatuilla de " << nombre_de_estatuilla(i, CANT_ESTATUILLAS) << "." << endl;
    }

    for(int i = 0; i < CANT_JUGADORES; i++){ // OBTIENE ESTATUILLA EN PRIMER INTENTO
        for(int j = 0; j < CANT_ESTATUILLAS; j++){
            if(intentos[i][j] == 1 && estatuillas[j] == i + 1){
                puntos_de_victoria[i] += PDV_POR_EST_PP;
                cout << "El jugador " << i + 1 << " gana " << PDV_POR_EST_PP << " puntos por haber obtenido la estatuilla de " << nombre_de_estatuilla(j, CANT_ESTATUILLAS) << " en el primer intento." << endl;
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
                cout << "El jugador " << i + 1 << " pierde " << PDV_POR_EST_RIVAL << " puntos por no haber ganado la estatuilla de " << nombre_de_estatuilla(j, CANT_ESTATUILLAS) << "." << endl;
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

int jugador_inicial_final(int estatuillas[], int const CANT_ESTATUILLAS, int const CANT_JUGADORES){
    // Determina el jugador que comienza la fase de expedicion.

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

    int const CANT_DADOS_FINAL = cant_dds;
    bool gana_por_escalera = true;
    bool gana_por_medusa = false;
    bool gana_fase_fin = false;
    int vueltas_sin_dar = 0;
    int aux;
    int dados_ordenados[CANT_DADOS_FINAL];

    for(int i = 0; i < CANT_DADOS_FINAL; i++){ // Copiar vector de dados para ser ordenado
        dados_ordenados[i] = dados_final[i];
    }

    for(int i = 0; i < CANT_DADOS_FINAL; i++){ // Ordenar de menor a mayor
        for(int j = 0; j < CANT_DADOS_FINAL - 1; j++){
            if(dados_ordenados[j+1] < dados_ordenados[j]){
                aux = dados_ordenados[j+1];
                dados_ordenados[j+1] = dados_ordenados[j];
                dados_ordenados[j] = aux;
            }
        }
    }

    if(turno_actual == portador_de_salamandra){ // Si tiene salamandra, mover el primer dado duplicado al final del array
        vueltas_sin_dar = 1;
        for(int i = 0; i < CANT_DADOS_FINAL - 1; i++){
            if(dados_ordenados[i] == dados_ordenados[i+1]){
                for(int j = i; j < CANT_DADOS_FINAL - i; j++){
                    dados_ordenados[j+1] = dados_ordenados[j+2];
                }
                dados_ordenados[CANT_DADOS_FINAL-1] = dados_ordenados[i];
                i = CANT_DADOS_FINAL - 1;
            }
        }
    }

    for(int i = 0; i < CANT_DADOS_FINAL - 1 - vueltas_sin_dar; i++){ // Gana por escalera
        if(dados_ordenados[i] + 1 != dados_ordenados[i+1]){
            gana_por_escalera = false;
        }
    }

    if(turno_actual == portador_de_medusa){ // Gana por medusa
        gana_por_medusa = true;
        for(int i = 0; i < CANT_DADOS_FINAL - 1; i++){
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

    if(gana_fase_fin == true){ // Informar ganador
        cout << "El jugador " << turno_actual << " gana la fase final con los dados ";
        for(int i = 0; i < CANT_DADOS_FINAL; i++){
            cout << dados_final[i];
            if(i < CANT_DADOS_FINAL - 2){
                 cout << ", ";
            } else if(i < CANT_DADOS_FINAL - 1){
                cout << " y ";
            } else{
                cout << "." << endl;
            }
        }
    }

    return gana_fase_fin;
}

void fase_final(string nombres_jugadores[], int const CANT_JUGADORES, int estatuillas[], int const CANT_ESTATUILLAS, int intentos[][5]){ //HARDCODEO
    // Jugar fase final.
    
    int const CANT_DADOS_FINAL = 5;
    int const CANT_CARAS_FINAL = 6;
    int dados_final[CANT_DADOS_FINAL] = {};
    int ganador_fase_fin;
    bool primer_tiro_cangrejo = false;
    int cambio_dado;
    int reemplazo_hormiga;
    int turno_actual = jugador_inicial_final(estatuillas, CANT_ESTATUILLAS, CANT_JUGADORES);

    cout << "El jugador " << estatuillas[1] << " tiene la estatuilla de la hormiga. Elegir un numero del 1 al 6 para luego usar como reemplazo." << endl;
    cin >> reemplazo_hormiga;

    cout << endl << "¡Comienza la fase final!" << endl;

    do{ // Tirar mientras no salga escalera
        cout << endl << "Turno de " << nombres_jugadores[turno_actual - 1] << endl;

        for(int i = 0; i < CANT_DADOS_FINAL; i++){ // Cada jugador tira los dados
            dados_final[i] = tirar_dado(CANT_CARAS_FINAL);
            cout << "Tira " << dados_final[i] << endl; //MOSTRARDADOS
        }

        if(turno_actual == estatuillas[1]){ // Si tiene hormiga, puede elegir un dado y cambiarlo por el reemplazo
            cout << "El jugador tiene la estatuilla de la hormiga. Elegir un dado para reemplazarlo por " << reemplazo_hormiga << ". ";
            cout << "Ingresar 0 en caso de no querer cambiar ningun dado." << endl;
            cin >> cambio_dado;

            if(cambio_dado != 0){
                for(int i = 0; i < CANT_DADOS_FINAL; i++){
                    if(dados_final[i] == cambio_dado){
                        dados_final[i] = reemplazo_hormiga;
                        i = CANT_DADOS_FINAL;
                    }
                }
            }
        }

        if(turno_actual == estatuillas[3]){ // Si tiene aguila, puede elegir un dado y asignarle un nuevo valor
            cout << "El jugador tiene la estatuilla del aguila. Elegir un dado para cambiar su valor. Ingresar 0 en caso de no querer cambiar ningun dado." << endl;
            cin >> cambio_dado;

            if(cambio_dado != 0){
                for(int i = 0; i < CANT_DADOS_FINAL; i++){
                    if(dados_final[i] == cambio_dado){
                        cout << "ingresar nuevo valor para el dado " << dados_final[i] << ":" << endl;
                        cin >> dados_final[i];
                        i = CANT_DADOS_FINAL;
                    }
                }
            }
        }

        ganador_fase_fin = turno_actual;

        if(primer_tiro_cangrejo == false && turno_actual == estatuillas[0] && fin_de_fase_fin(dados_final, CANT_DADOS_FINAL, turno_actual, estatuillas[2], estatuillas[4]) == false){ // Si tiene cangrejo, no cambia el turno porque tira el jugador nuevamente
            primer_tiro_cangrejo = true;
            cout << "El jugador " << turno_actual << " tira nuevamente por tener la estatuilla del cangrejo." << endl;
        } else{
            turno_actual = turno_nuevo(turno_actual, CANT_JUGADORES);
        }
    } while(fin_de_fase_fin(dados_final, CANT_DADOS_FINAL, ganador_fase_fin, estatuillas[2], estatuillas[4]) == false);

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

bool guardar_inventario(int dados_exp[], int objetivos[], int const CANT_ESTATUILLAS, int turno_actual){
    // Determina si corresponde que un jugador gane una estatuilla en funcion de los dados que tira y el objetivo que haya elegido.
    
    bool rtn = false;
    bool ests_coinciden[CANT_ESTATUILLAS]; // Array que tiene verdaderos en los componentes que verifican los requisitos de obtencion. Los elementos son hardcodeados porque hay que agregar manualmente la condicion de cada estatuilla.
    
    ests_coinciden[0] = arena_cangrejo(dados_exp[0], dados_exp[1], dados_exp[2]);
    ests_coinciden[1] = tierra_hormiga(dados_exp[0], dados_exp[1], dados_exp[2]);
    ests_coinciden[2] = agua_medusa(dados_exp[0], dados_exp[1], dados_exp[2]);
    ests_coinciden[3] = aire_aguila(dados_exp[0], dados_exp[1], dados_exp[2]);
    ests_coinciden[4] = fuego_salamandra(dados_exp[0], dados_exp[1], dados_exp[2]);

    if(ests_coinciden[objetivos[turno_actual - 1] - 1] == 1){
        rtn = true;
        cout << endl << "El jugador " << turno_actual << " gana la estatuilla de " << nombre_de_estatuilla(objetivos[turno_actual - 1] - 1, CANT_ESTATUILLAS) << endl;
    }

    return rtn;
}

int turno_nuevo(int turno_actual, int const CANT_JUGADORES){
    // Alterna el turno entre los jugadores a partir del numero de turno actual.

    int turno_nuevo;

    if(turno_actual < CANT_JUGADORES){
        turno_nuevo = turno_actual + 1;
    } else{
        turno_nuevo = 1;
    }

    return turno_nuevo;
}

string nombre_de_estatuilla(int numero_de_estat, int const CANT_ESTATUILLAS){
    // Devuelve el nombre de una de las estatuillas.

    string nombres_de_estat[CANT_ESTATUILLAS]; // Array que tiene por componentes los nombres de cada estatuilla. Los elementos son hardcodeados porque hay que agregar manualmente el nombre de cada estatuilla.
    nombres_de_estat[0] = "arena: Cangrejo";
    nombres_de_estat[1] = "tierra: Hormiga";
    nombres_de_estat[2] = "agua: Medusa";
    nombres_de_estat[3] = "aire: Aguila";
    nombres_de_estat[4] = "fuego: Salamandra";

    return nombres_de_estat[numero_de_estat];
}

void mostrar_inventario(string nombres_jugadores[], int const CANT_JUGADORES, int estatuillas[], int const CANT_ESTATUILLAS){
    // Muestra las estatuillas adquiridas por cada jugador hasta el momento.

    cout << endl;

    for(int i = 0; i < CANT_JUGADORES; i++){
        cout << "Inventario de " << nombres_jugadores[i] << ":" << endl;

        for(int j = 0; j < CANT_ESTATUILLAS; j++){
            if(estatuillas[j] == i + 1){
                cout << "- Estatuilla de " << nombre_de_estatuilla(j, CANT_ESTATUILLAS) << endl;
            }
        }
    }

    cout << endl;
}

void elegir_estatuillas_disponibles(int estatuillas[], int const CANT_ESTATUILLAS){
    // Mostrar las estatuillas disponibles para elegir como objetivo durante fase de expedicion.

    cout << "Elegir estatuilla objetivo:" << endl;

    for(int i = 0; i < CANT_ESTATUILLAS; i++){
        if(estatuillas[i] == 0){
            cout << i + 1 << " - Estatuilla de " << nombre_de_estatuilla(i, CANT_ESTATUILLAS) << endl;
        }
    }
}

int tirar_dado(int cant_caras){
    // Devuelve un numero aleatorio con probabilidad de uno entre la cantidad de caras.

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

    while(dado_jugador_1 == dado_jugador_2){ //MOSTRARDADOS
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

bool fin_de_fase_exp(int estatuillas[], int const CANT_ESTATUILLAS){
    // Determina si se termina la fase de expedicion.

    bool rtn = true;

    for(int i = 0; i < CANT_ESTATUILLAS; i++){
        if(estatuillas[i] == 0){
            rtn = false;
        }
    }

    return rtn;
}

void fase_expedicion(string nombres_jugadores[], int const CANT_JUGADORES){
    // Jugar fase de expedicion.

    int const CANT_ESTATUILLAS = 5;
    int const CANT_DADOS_EXP = 3;
    int const CANT_CARAS_EXP = 10;
    int const TIROS_MALDICION_AGUILA = 2;
    int const TURNOS_MALDICION_MEDUSA = 3;
    int intentos[CANT_JUGADORES][CANT_ESTATUILLAS]; // Matriz que contiene las veces que un jugador eligio una estatuilla como objetivo. Cada fila representa un jugador. Cada columna representa una estatuilla.
    int estatuillas[CANT_ESTATUILLAS] = {}; // Array que tiene en cada componente a quien pertenece la estatuilla o tiene cero si nadie la tiene.
    int objetivos[CANT_JUGADORES]; // Array que tiene el objetivo de cada jugador por turno. Entero mayor que cero.
    int dados_exp[CANT_DADOS_EXP]; // Array de dados usados en fase de expedicion. Si el tercer dado no se usa, este debe valer cero.
    int turnos_perdidos = 0;
    int tiros;
    int turno_actual = jugador_inicial_exp(); // Numero de jugador al que le corresponde el turno. Entero mayor que cero.

    for(int i = 0; i < CANT_JUGADORES; i++){
        for(int j = 0; j < CANT_ESTATUILLAS; j++){
            intentos[i][j] = 0;
        }
    }

    cout << endl << "¡Comienza la fase de expedicion!" << endl;

    while(fin_de_fase_exp(estatuillas, CANT_ESTATUILLAS) == false){ // Mientras haya estatuillas disponibles, elegir objetivo y tirar dados
        mostrar_inventario(nombres_jugadores, CANT_JUGADORES, estatuillas, CANT_ESTATUILLAS);

        for(int i = 0; i < CANT_JUGADORES; i++){ // Cada jugador elige un objetivo
            if(estatuillas[2] == turno_actual && turnos_perdidos < TURNOS_MALDICION_MEDUSA){ // Si el jugador tiene la medusa, no elige objetivo por 3 turnos
                cout << nombres_jugadores[turno_actual - 1] << " tiene la medusa y pierde los siguientes " << TURNOS_MALDICION_MEDUSA - turnos_perdidos << " turnos."  << endl;
            } else{
                cout << "Turno de " << nombres_jugadores[turno_actual - 1] << endl;
                elegir_estatuillas_disponibles(estatuillas, CANT_ESTATUILLAS);
                cin >> objetivos[turno_actual - 1];
                intentos[turno_actual - 1][objetivos[turno_actual - 1] - 1] ++;
            }

            turno_actual = turno_nuevo(turno_actual, CANT_JUGADORES);
        }

        for(int i = 0; i < CANT_JUGADORES; i++){ // Cada jugador tira los dados
            cout << "Turno de " << nombres_jugadores[turno_actual - 1] << endl;

            if(estatuillas[2] == turno_actual && turnos_perdidos < TURNOS_MALDICION_MEDUSA){ // Si el jugador tiene la medusa, no tira por 3 turnos
                tiros = 0;
                turnos_perdidos ++;
            } else if(estatuillas[3] != 0 && estatuillas[3] != turno_actual){ // Si el rival tiene el aguila, tiene 2 tiros
                tiros = TIROS_MALDICION_AGUILA;
            } else{
                tiros = 1;
            }

            for(int i = 0; i < tiros; i++){ // Tirar dados y guardar estatuilla si corresponde
                for(int i = 0; i < CANT_DADOS_EXP; i++){
                    dados_exp[i] = tirar_dado(CANT_CARAS_EXP);
                }

                if(estatuillas[4] == 0 || estatuillas[4] == turno_actual){ // Si nadie tiene la salamandra o la tiene el del turno, este tira dos dados
                    dados_exp[2] = 0;
                }
                
                cout << nombres_jugadores[turno_actual-1] << " tira los dados " << dados_exp[0] << dados_exp[1] << dados_exp[2] << endl; //MOSTRARDADOS
                
                if(estatuillas[objetivos[turno_actual - 1] - 1] == 0 && guardar_inventario(dados_exp, objetivos, CANT_ESTATUILLAS, turno_actual) == 1){
                    estatuillas[objetivos[turno_actual - 1] - 1] = turno_actual;
                }
            }

            turno_actual = turno_nuevo(turno_actual, CANT_JUGADORES);
        }
    }

    fase_final(nombres_jugadores, CANT_JUGADORES, estatuillas, CANT_ESTATUILLAS, intentos);
}

void menu_jugar(int const CANT_JUGADORES){
    // Opcion del menu.

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