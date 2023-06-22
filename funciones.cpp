#include <iostream>
#include <random>
using namespace std;
#include "funciones.h"
#include "rlutil.h"

void limpiar_terminal(){
    // Limpia la terminal.

    system("clear"); // MacOs
    // system("cls"); // Windows
}

void ingresar_cero_para_continuar(){
    // Pausa el flujo del programa hasta que el usuario ingrese cero.
    
    int aux = 1;

    do{
        cout << "Ingresar 0 para continuar" << endl;
        cin >> aux;
    } while(aux != 0);
}

void dibujar_dado(int valor_del_dado, int posicion, int desfasaje_vertical){
    // Dibuja un dado de cierto valor. La posicion es un numero entero y varia horizontalmente.

    string const FONDO_DE_DADO = "█"; // MacOs
    string const PUNTO_DE_DADO = "░░"; // MacOs
    // string const FONDO_DE_DADO = char(219); // Windows
    // string const PUNTO_DE_DADO = "  "; // Windows
    int const LARGO = 19;
    int const ALTO = 10;
    int const FIL_1 = 2 + desfasaje_vertical;
    int const FIL_2 = 5 + desfasaje_vertical;
    int const FIL_3 = 8 + desfasaje_vertical;
    int const COL_1 = 3;
    int const COL_2 = 9;
    int const COL_3 = 15;
    int mostrar_lineas;

    for(int x = 1; x < LARGO; x++){ // Dibujar cuadrado
        for(int y = 1; y < ALTO; y++){
            rlutil::locate(x + LARGO * posicion, y + desfasaje_vertical);
            cout << FONDO_DE_DADO << endl;
        }
    }

    switch (valor_del_dado){
        case 1:
            rlutil::locate(COL_2 + LARGO * posicion, FIL_2);
            cout << PUNTO_DE_DADO << endl;
            break;

        case 2:
            rlutil::locate(COL_1 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_3 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;
            break;

        case 3:
            rlutil::locate(COL_1 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_2 + LARGO * posicion, FIL_2);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_3 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;
            break;

        case 4:
            rlutil::locate(COL_1 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_1 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_3 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_3 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;
            break;

        case 5:
            rlutil::locate(COL_1 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_1 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_2 + LARGO * posicion, FIL_2);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_3 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_3 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;
            break;

        case 6:
            rlutil::locate(COL_1 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_1 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_2 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_2 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_3 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_3 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;
            break;
        
        case 7:
            rlutil::locate(COL_1 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_1 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_2 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_2 + LARGO * posicion, FIL_2);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_2 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_3 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_3 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;
            break;

        case 8:
            rlutil::locate(COL_1 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_1 + LARGO * posicion, FIL_2);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_1 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_2 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_2 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_3 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_3 + LARGO * posicion, FIL_2);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_3 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;
            break;

        case 9:
            rlutil::locate(COL_1 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_1 + LARGO * posicion, FIL_2);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_1 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_2 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_2 + LARGO * posicion, FIL_2);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_2 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_3 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_3 + LARGO * posicion, FIL_2);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_3 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;
            break;

        case 10:
            rlutil::locate(COL_1 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_1 + LARGO * posicion, FIL_2);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_1 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_2 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(7 + LARGO * posicion, FIL_2);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(11 + LARGO * posicion, FIL_2);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_2 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_3 + LARGO * posicion, FIL_1);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_3 + LARGO * posicion, FIL_2);
            cout << PUNTO_DE_DADO << endl;

            rlutil::locate(COL_3 + LARGO * posicion, FIL_3);
            cout << PUNTO_DE_DADO << endl;
            break;
    }

    if(valor_del_dado == 1){
        mostrar_lineas = 5;
    } else{
        mostrar_lineas = 2;
    }

    for(int y = 0; y < mostrar_lineas; y++){
        cout << endl;
    }
}

void mostrar_dados(int dados[], int const CANT_DADOS, bool clear_cls, int desfasaje_vertical){
    // Muestra los dados tirados que hay en un vector de dados.

    for(int i = 0; i < CANT_DADOS; i++){
        if(dados[i] != 0){
            dibujar_dado(dados[i], i, desfasaje_vertical);
        }
    }

    ingresar_cero_para_continuar();
    
    if(clear_cls == true){
        limpiar_terminal();
    }
}

int array_cuantos_repite(int arr[], int tam){
    // Devuelve la cantidad de veces que se repite el entero que mas se repite en un array.

    int rtn = 0;
    int min = 1; // Valor del numero entero minimo del array.
    int max = arr[indice_max(arr, tam)]; // Valor del numero entero maximo del array.

    for(int i = min; i <= max; i++){
        if(rtn < array_repite_numero(arr, tam, i)){
            rtn = array_repite_numero(arr, tam, i);
        }
    }

    return rtn;
}

int array_repite_numero(int arr[], int tam, int num){
    // Devuelve la cantidad de veces que un entero se repite en un array.

    int rtn = 0;

    for(int i = 0; i < tam; i++){
        if(arr[i] == num){
            rtn += 1;
        }
    }

    return rtn;
}

bool array_contiene_numero(int arr[], int tam, int num){
    // Determina si un numero se encuentra en un array.

    bool rtn = false;

    for(int i = 0; i < tam; i++){
        if(arr[i] == num){
            rtn = true;
        }
    }

    return rtn;
}

int indice_max(int arr[], int tam){
    // Devuelve el indice del componente maximo de un array.

    int max = arr[0];
    int indice = 0;

    for(int i = 1; i < tam; i++){
        if(max < arr[i]){
            max = arr[i];
            indice = i;
        }
    }

    return indice;
}

void puntos_de_victoria(string nombres_jugadores[], int const CANT_JUGADORES, int estatuillas[], int const CANT_ESTATUILLAS, int ganador_fase_fin, int intentos[][5], int puntos_maldicion_cangrejo, int puntos_maldicion_hormiga, int& max_pdv, string& max_jugador){
    // Suma los puntos de victoria para determinar el ganador.

    int const PDV_POR_ESTAT = 5;
    int const PDV_POR_EST_PP = 10;
    int const PDV_POR_GANADOR = 15;
    int const PDV_POR_GAN_PP = 50;
    int const PDV_POR_EST_RIVAL = 3;
    int const PDV_POR_LANZAM = 1;
    int pts_de_vic[CANT_JUGADORES]; // Array acumulador de puntos. Cada componente tiene los puntos de cada jugador.

    for(int i = 0; i < CANT_JUGADORES; i++){
        pts_de_vic[i] = 0;
    }

    pts_de_vic[estatuillas[0] - 1] -= puntos_maldicion_cangrejo;
    cout << nombres_jugadores[estatuillas[0] - 1] << " perdio " << puntos_maldicion_cangrejo << " puntos por tener la maldicion del cangrejo." << endl;
    
    pts_de_vic[estatuillas[1] - 1] -= puntos_maldicion_hormiga;
    cout << nombres_jugadores[estatuillas[1] - 1] << " perdio " << puntos_maldicion_hormiga << " puntos por tener la maldicion de la hormiga." << endl;

    for(int i = 0; i < CANT_ESTATUILLAS; i++){ // OBTIENE ESTATUILLA
        pts_de_vic[estatuillas[i] - 1] += PDV_POR_ESTAT;
        cout << nombres_jugadores[estatuillas[i] - 1] << " gana " << PDV_POR_ESTAT << " puntos por haber obtenido la estatuilla de " << nombre_de_estatuilla(i, CANT_ESTATUILLAS) << "." << endl;
    }

    for(int i = 0; i < CANT_JUGADORES; i++){ // OBTIENE ESTATUILLA EN PRIMER INTENTO
        for(int j = 0; j < CANT_ESTATUILLAS; j++){
            if(intentos[i][j] == 1 && estatuillas[j] == i + 1){
                pts_de_vic[i] += PDV_POR_EST_PP;
                cout << nombres_jugadores[i] << " gana " << PDV_POR_EST_PP << " puntos por haber obtenido la estatuilla de " << nombre_de_estatuilla(j, CANT_ESTATUILLAS) << " en el primer intento." << endl;
            }
        }
    }

    pts_de_vic[ganador_fase_fin - 1] += PDV_POR_GANADOR; // GANADOR FASE FINAL
    cout << nombres_jugadores[ganador_fase_fin - 1] << " gana " << PDV_POR_GANADOR << " puntos por haber ganado la fase final." << endl;

    for(int i = 0; i < CANT_JUGADORES; i++){ // GANADOR FASE FINAL SIN ESTATUILLAS
        bool gano_sin_ests = true;
        
        for(int j = 0; j < CANT_ESTATUILLAS; j++){
            if(ganador_fase_fin != i || estatuillas[j] == i){
                gano_sin_ests = false;
            }
        }

        if(gano_sin_ests == true){
            pts_de_vic[i] += PDV_POR_GAN_PP;
            cout << nombres_jugadores[i] << " gana " << PDV_POR_GAN_PP << " puntos por haber ganado la fase final sin estatuillas en su inventario." << endl;
        }
    }

    for(int i = 0; i < CANT_JUGADORES; i++){ // RIVAL OBTIENE ESTATUILLA
        for(int j = 0; j < CANT_ESTATUILLAS; j++){
            if(estatuillas[j] != i + 1){
                pts_de_vic[i] -= PDV_POR_EST_RIVAL;
                cout << nombres_jugadores[i] << " pierde " << PDV_POR_EST_RIVAL << " puntos por no haber ganado la estatuilla de " << nombre_de_estatuilla(j, CANT_ESTATUILLAS) << "." << endl;
            }
        }
    }

    for(int i = 0; i < CANT_JUGADORES; i++){ // LANZADOR FASE FINAL
        if(jugador_inicial_final(estatuillas, CANT_ESTATUILLAS, CANT_JUGADORES) == i + 1){
            pts_de_vic[i] -= PDV_POR_LANZAM;
            cout << nombres_jugadores[i] << " pierde " << PDV_POR_LANZAM << " punto por haber lanzado en fase final." << endl;
        }
    }

    for(int i = 0; i < CANT_JUGADORES; i++){
        if(pts_de_vic[i] < 0){
            pts_de_vic[i] = 0;
        }
        cout << nombres_jugadores[i] << " obtuvo " << pts_de_vic[i] << " puntos de victoria." << endl;
    }

    if(max_pdv < pts_de_vic[indice_max(pts_de_vic, CANT_JUGADORES)]){
        max_pdv = pts_de_vic[indice_max(pts_de_vic, CANT_JUGADORES)];
        max_jugador = nombres_jugadores[indice_max(pts_de_vic, CANT_JUGADORES)];
    }

    cout << endl << nombres_jugadores[indice_max(pts_de_vic, CANT_JUGADORES)] << " gana!" << endl;
    ingresar_cero_para_continuar();
    limpiar_terminal();
    menu(max_pdv, max_jugador);
}

int jugador_inicial_final(int estatuillas[], int const CANT_ESTATUILLAS, int const CANT_JUGADORES){
    // Determina el jugador que comienza la fase final.

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
        cout << "Gana la fase final con los dados:" << endl;
        mostrar_dados(dados_final, CANT_DADOS_FINAL, true, 5);
    }

    return gana_fase_fin;
}

void fase_final(bool modo_aleatorio, string nombres_jugadores[], int const CANT_JUGADORES, int estatuillas[], int const CANT_ESTATUILLAS, int intentos[][5], int& max_pdv, string& max_jugador){ // Dimension de matriz hardcodeada para no usar constantes globales
    // Jugar fase final.
    
    int const CANT_DADOS_FINAL = 5;
    int const CANT_CARAS_FINAL = 6;
    int const DADOS_MALDICION_CANGREJO = 1;
    int const CARAS_MALDICION_CANGREJO = 10;
    int const DADOS_MALDICION_HORMIGA = 2;
    int const CARAS_MALDICION_HORMIGA = 10;
    int const LINEAS_TERMINAL_FASE_FIN = 5;
    int dados_final[CANT_DADOS_FINAL] = {};
    int ganador_fase_fin;
    int puntos_maldicion_cangrejo = 0;
    int puntos_maldicion_hormiga = 0;
    bool primer_tiro_cangrejo = false;
    int cambio_dado;
    int reemplazo_hormiga = 0;
    int turno_actual = jugador_inicial_final(estatuillas, CANT_ESTATUILLAS, CANT_JUGADORES);

    cout << nombres_jugadores[estatuillas[0] - 1] << " tiene la maldicion del cangrejo. " << nombres_jugadores[turno_nuevo(estatuillas[0], CANT_JUGADORES) - 1] << " tira " << DADOS_MALDICION_CANGREJO << " dado para descontarle puntaje a " << nombres_jugadores[estatuillas[0] - 1] << endl;
    
    for(int i = 0; i < DADOS_MALDICION_CANGREJO; i++){
        dados_final[i] = tirar_dado(CARAS_MALDICION_CANGREJO, modo_aleatorio);
        puntos_maldicion_cangrejo += dados_final[i];
    }
    
    mostrar_dados(dados_final, DADOS_MALDICION_CANGREJO, true, LINEAS_TERMINAL_FASE_FIN);

    cout << nombres_jugadores[estatuillas[1] - 1] << " tiene la maldicion de la hormiga. " << nombres_jugadores[turno_nuevo(estatuillas[1], CANT_JUGADORES) - 1] << " tira " << DADOS_MALDICION_HORMIGA << " dados para descontarle puntaje a " << nombres_jugadores[estatuillas[1] - 1] << endl;
    
    for(int i = 0; i < DADOS_MALDICION_HORMIGA; i++){
        dados_final[i] = tirar_dado(CARAS_MALDICION_HORMIGA, modo_aleatorio);
        puntos_maldicion_hormiga += dados_final[i];
    }

    mostrar_dados(dados_final, DADOS_MALDICION_HORMIGA, true, LINEAS_TERMINAL_FASE_FIN);

    do{
        cout << nombres_jugadores[estatuillas[1] - 1] << " tiene la bendicion de la hormiga. Elegir un numero del 1 al 6 para luego usar como reemplazo." << endl;
        cin >> reemplazo_hormiga;
    } while(reemplazo_hormiga < 1 || 6 < reemplazo_hormiga);

    limpiar_terminal();
    cout << endl << "¡Comienza la fase final!" << endl;

    do{ // Tirar mientras no salga escalera
        cout << endl << "Turno de " << nombres_jugadores[turno_actual - 1] << endl;

        for(int i = 0; i < CANT_DADOS_FINAL; i++){ // Cada jugador tira los dados
            dados_final[i] = tirar_dado(CANT_CARAS_FINAL, modo_aleatorio);
        }

        mostrar_dados(dados_final, CANT_DADOS_FINAL, false, LINEAS_TERMINAL_FASE_FIN);

        if(turno_actual == estatuillas[1]){ // Si tiene hormiga, puede elegir un dado y cambiarlo por el reemplazo
            do{
                cout << nombres_jugadores[turno_actual - 1] << " tiene la bendicion de la hormiga. Elegir un dado para reemplazarlo por " << reemplazo_hormiga << ". ";
                cout << "Ingresar 0 en caso de no querer cambiar ningun dado." << endl;
                cin >> cambio_dado;
            } while(array_contiene_numero(dados_final, CANT_DADOS_FINAL, cambio_dado) == false && cambio_dado != 0);

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
            do{
                cout << nombres_jugadores[turno_actual - 1] << " tiene la bendicion del aguila. Elegir un dado para cambiar su valor. Ingresar 0 en caso de no querer cambiar ningun dado." << endl;
                cin >> cambio_dado;
            } while(array_contiene_numero(dados_final, CANT_DADOS_FINAL, cambio_dado) == false && cambio_dado != 0);

            if(cambio_dado != 0){
                for(int i = 0; i < CANT_DADOS_FINAL; i++){
                    if(dados_final[i] == cambio_dado){
                        do{
                            cout << "ingresar nuevo valor para el dado " << dados_final[i] << ":" << endl;
                            cin >> dados_final[i];
                        } while(dados_final[i] < 1 || CANT_CARAS_FINAL < dados_final[i]);
                        
                        i = CANT_DADOS_FINAL;
                    }
                }
            }
        }

        ganador_fase_fin = turno_actual;
        limpiar_terminal();

        if(primer_tiro_cangrejo == false && turno_actual == estatuillas[0] && fin_de_fase_fin(dados_final, CANT_DADOS_FINAL, turno_actual, estatuillas[2], estatuillas[4]) == false){ // Si tiene cangrejo, no cambia el turno porque tira el jugador nuevamente
            primer_tiro_cangrejo = true;
            cout << nombres_jugadores[turno_actual - 1] << " tira nuevamente por tener la bendicion del cangrejo." << endl;
        } else{
            turno_actual = turno_nuevo(turno_actual, CANT_JUGADORES);
        }
    } while(fin_de_fase_fin(dados_final, CANT_DADOS_FINAL, ganador_fase_fin, estatuillas[2], estatuillas[4]) == false);

    puntos_de_victoria(nombres_jugadores, CANT_JUGADORES, estatuillas, CANT_ESTATUILLAS, ganador_fase_fin, intentos, puntos_maldicion_cangrejo, puntos_maldicion_hormiga, max_pdv, max_jugador);
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
        cout << endl << "Ganaste la estatuilla de " << nombre_de_estatuilla(objetivos[turno_actual - 1] - 1, CANT_ESTATUILLAS) << endl;
        ingresar_cero_para_continuar();
        limpiar_terminal();
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

int tirar_dado(int cant_caras, bool modo_aleatorio){
    // Devuelve un numero aleatorio con probabilidad de uno entre la cantidad de caras. Si el modo aleatorio esta desactivado, los valores de los dados se pueden ingresar manualmente.

    int dado;

    if(modo_aleatorio == 1){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> aleatorio(1, cant_caras);
        dado = aleatorio(gen);
    } else{
        cout << "Ingresar valor de dado:" << endl;
        cin >> dado;
        limpiar_terminal();
    }


    return dado;
}

int jugador_inicial_exp(bool modo_aleatorio, string nombres_jugadores[], int const CANT_JUGADORES){
    // Determina el jugador que comienza la fase de expedicion.

    int const CANT_DADOS_LANZ = 2;
    int jugador_inicial;
    int dados_lanz[CANT_DADOS_LANZ] = {};

    while(dados_lanz[0] == dados_lanz[1]){
        limpiar_terminal();
        for(int i = 0; i < CANT_JUGADORES; i++){
            dados_lanz[i] = tirar_dado(10, modo_aleatorio);
            cout << nombres_jugadores[i] << " tira el dado:" << endl;
            dibujar_dado(dados_lanz[i],0, 2);
            ingresar_cero_para_continuar();
            limpiar_terminal();
        }
    }

    if(dados_lanz[0] < dados_lanz[1]){
        jugador_inicial = 1;
    } else{
        jugador_inicial = 2;
    }

    cout << "¡Comienza " << nombres_jugadores[jugador_inicial - 1] << " la fase de expedicion por haber tirado el dado de menor valor!" << endl;
    ingresar_cero_para_continuar();
    limpiar_terminal();

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

void fase_expedicion(bool modo_aleatorio, string nombres_jugadores[], int const CANT_JUGADORES, int& max_pdv, string& max_jugador){
    // Jugar fase de expedicion.

    int const CANT_ESTATUILLAS = 5;
    int const CANT_DADOS_EXP = 3; // Cantidad maxima de dados que un jugador puede tirar en un tiro en la fase de expedicion.
    int const CANT_CARAS_EXP = 10;
    int const TIROS_MALDICION_AGUILA = 2;
    int const TURNOS_MALDICION_MEDUSA = 3;
    int const LINEAS_TERMINAL_FASE_EXP = 6;
    int intentos[CANT_JUGADORES][CANT_ESTATUILLAS]; // Matriz que contiene las veces que un jugador eligio una estatuilla como objetivo. Cada fila representa un jugador. Cada columna representa una estatuilla.
    int estatuillas[CANT_ESTATUILLAS] = {}; // Array que tiene en cada componente a quien pertenece la estatuilla o tiene cero si nadie la tiene.
    int objetivos[CANT_JUGADORES]; // Array que tiene el objetivo de cada jugador por turno. Entero mayor que cero.
    int dados_exp[CANT_DADOS_EXP]; // Array de dados usados en fase de expedicion. Si el tercer dado no se usa, este debe valer cero.
    int cant_dds_exp; // Cantidad de dados que le corresponde tirar a un jugador segun el rival tenga o no la salamandra.
    int turnos_perdidos = 0;
    int tiros;
    int turno_actual = jugador_inicial_exp(modo_aleatorio, nombres_jugadores, CANT_JUGADORES); // Numero de jugador al que le corresponde el turno. Entero mayor que cero.

    for(int i = 0; i < CANT_JUGADORES; i++){
        for(int j = 0; j < CANT_ESTATUILLAS; j++){
            intentos[i][j] = 0;
        }
    }

    while(fin_de_fase_exp(estatuillas, CANT_ESTATUILLAS) == false){ // Mientras haya estatuillas disponibles, elegir objetivo y tirar dados
        for(int i = 0; i < CANT_JUGADORES; i++){ // Cada jugador elige un objetivo
            mostrar_inventario(nombres_jugadores, CANT_JUGADORES, estatuillas, CANT_ESTATUILLAS);

            if(estatuillas[2] == turno_actual && turnos_perdidos < TURNOS_MALDICION_MEDUSA){ // Si el jugador tiene la medusa, no elige objetivo por 3 turnos
                cout << nombres_jugadores[turno_actual - 1] << " tiene la maldicion de la medusa y pierde los siguientes " << TURNOS_MALDICION_MEDUSA - turnos_perdidos << " turnos."  << endl;
                ingresar_cero_para_continuar();
            } else{
                cout << "Turno de " << nombres_jugadores[turno_actual - 1] << endl;
                
                do{
                    elegir_estatuillas_disponibles(estatuillas, CANT_ESTATUILLAS);
                    cin >> objetivos[turno_actual - 1];
                } while(objetivos[turno_actual - 1] < 1 || CANT_ESTATUILLAS < objetivos[turno_actual - 1] || estatuillas[objetivos[turno_actual - 1] - 1] != 0);

                intentos[turno_actual - 1][objetivos[turno_actual - 1] - 1] ++;
            }

            turno_actual = turno_nuevo(turno_actual, CANT_JUGADORES);
            limpiar_terminal();
        }

        limpiar_terminal();

        for(int i = 0; i < CANT_JUGADORES; i++){ // Cada jugador tira los dados
            if(estatuillas[2] == turno_actual && turnos_perdidos < TURNOS_MALDICION_MEDUSA){ // Si el jugador tiene la medusa, no tira por 3 turnos
                tiros = 0;
                turnos_perdidos ++;
            } else if(estatuillas[3] != 0 && estatuillas[3] != turno_actual){ // Si el rival tiene el aguila, el jugador actual tiene 2 tiros
                tiros = TIROS_MALDICION_AGUILA;
            } else{
                tiros = 1;
            }

            if(estatuillas[4] == 0 || estatuillas[4] == turno_actual){ // Si nadie tiene la salamandra o la tiene el del turno, este tira dos dados
                dados_exp[2] = 0;
                cant_dds_exp = 2;
            } else{
                cant_dds_exp = CANT_DADOS_EXP;
            }

            for(int i = 0; i < tiros; i++){ // Hacer tantos tiros de tantos dados y guardar estatuilla si corresponde
                mostrar_inventario(nombres_jugadores, CANT_JUGADORES, estatuillas, CANT_ESTATUILLAS);
                cout << "Turno de " << nombres_jugadores[turno_actual - 1] << endl;

                for(int i = 0; i < cant_dds_exp; i++){
                    dados_exp[i] = tirar_dado(CANT_CARAS_EXP, modo_aleatorio);
                }
                
                cout << nombres_jugadores[turno_actual-1] << " tira los dados:" << endl;
                mostrar_dados(dados_exp, cant_dds_exp, true, LINEAS_TERMINAL_FASE_EXP + array_cuantos_repite(estatuillas, CANT_ESTATUILLAS));
                
                if(estatuillas[objetivos[turno_actual - 1] - 1] == 0 && guardar_inventario(dados_exp, objetivos, CANT_ESTATUILLAS, turno_actual) == 1){
                    estatuillas[objetivos[turno_actual - 1] - 1] = turno_actual;
                }
            }

            turno_actual = turno_nuevo(turno_actual, CANT_JUGADORES);
        }
    }

    fase_final(modo_aleatorio, nombres_jugadores, CANT_JUGADORES, estatuillas, CANT_ESTATUILLAS, intentos, max_pdv, max_jugador);
}

void menu_jugar(int const CANT_JUGADORES, int& max_pdv, string& max_jugador){
    // Iniciar nueva partida.

    bool modo_aleatorio = 1;
    string nombres_jugadores[CANT_JUGADORES];

    limpiar_terminal();
    cin.ignore(); // Ignora el enter de cin >> seleccion en menu();

    for(int i = 0; i < CANT_JUGADORES; i++){
        cout << "Ingrese nombre del jugador " << i + 1 << ":" << endl;
        getline(cin, nombres_jugadores[i]);
    }

    if(nombres_jugadores[0] == "LAB1"){
        modo_aleatorio = 0;
        cout << "Modo aleatorio desactivado. Los dados se ingresaran manualmente." << endl;
    }

    ingresar_cero_para_continuar();
    fase_expedicion(modo_aleatorio, nombres_jugadores, CANT_JUGADORES, max_pdv, max_jugador);
}

void menu_estadisticas(int max_pdv, string max_jugador){
    // Mostrar el jugador que mayor puntos de victoria haya obtenido.

    limpiar_terminal();
    cout << max_jugador << ":\t" << max_pdv << " PDV" << endl;
    ingresar_cero_para_continuar();
    limpiar_terminal();
    menu(max_pdv, max_jugador);
}

void menu_creditos(int max_pdv, string max_jugador){
    // Opcion del menu.

    limpiar_terminal();
    cout << "Irwin's Revenge es un juego creado por Gonzalo Ligero." << endl << endl;
    cout << "El equipo de desarrolladores Algoritmos Anidados esta conformado por:" << endl;
    cout << "- Malvicino, Maximiliano (Legajo 28825)" << endl;
    cout << "- Serman, Guido (Legajo 28842)" << endl << endl;
    ingresar_cero_para_continuar();
    limpiar_terminal();
    menu(max_pdv, max_jugador);
}

void menu(int& max_pdv, string& max_jugador){
    // Menu principal.

    int const CANT_JUGADORES = 2;

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

    switch(seleccion){
        case 0:
            break;
        case 1:
            menu_jugar(CANT_JUGADORES, max_pdv, max_jugador);
            break;
        case 2:
            menu_estadisticas(max_pdv, max_jugador);
            break;
        case 3:
            menu_creditos(max_pdv, max_jugador);
            break;
    }
}