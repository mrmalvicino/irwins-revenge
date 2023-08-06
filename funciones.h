#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
using namespace std;

void limpiar_terminal();
void pausar_terminal();
void dibujar_dado(int valor_del_dado, int posicion, int desfasaje_vertical);
void mostrar_dados(int dados[], int const CANT_DADOS, bool clear_cls, int desfasaje_vertical);
bool array_contiene_numero(int arr[], int tam, int num);
int indice_max(int arr[], int tam);
void puntos_de_victoria(string jugadores_final[], int const CANT_JUGADORES, int estatuillas[], int const CANT_ESTATUILLAS, int ganador_fase_fin, int intentos[][5], int puntos_maldicion_cangrejo, int puntos_maldicion_hormiga, int& max_pdv, string& max_jugador, int orden_ests[]);
int jugador_inicial_final(int estatuillas[], int const CANT_ESTATUILLAS, int const CANT_JUGADORES);
bool fin_de_fase_fin(int dados_ordenados[], int cant_dds, int turno_actual, int portador_de_medusa, int portador_de_salamandra);
void fase_final(bool modo_aleatorio, string jugadores_fase_exp[], int const CANT_JUGADORES, int estatuillas[], int const CANT_ESTATUILLAS, int intentos[][5], int& max_pdv, string& max_jugador, int orden_ests[]);
bool arena_cangrejo(int dado1, int dado2, int dado3);
bool tierra_hormiga(int dado1, int dado2, int dado3);
bool agua_medusa(int dado1, int dado2, int dado3);
bool aire_aguila(int dado1, int dado2, int dado3);
bool fuego_salamandra(int dado1, int dado2, int dado3);
bool guardar_inventario(int dados_exp[], int objetivos[], int const CANT_ESTATUILLAS, int turno_actual);
int turno_nuevo(int turno_actual, int const CANT_JUGADORES);
string nombre_hito(int numero_de_hito, int const CANT_HITOS);
string nombre_de_estatuilla(int numero_de_estat, int const CANT_ESTATUILLAS);
void mostrar_inventario(string jugadores_fase_exp[], int const CANT_JUGADORES, int estatuillas[], int const CANT_ESTATUILLAS);
void elegir_estatuillas_disponibles(int estatuillas[], int const CANT_ESTATUILLAS);
int tirar_dado(int cant_caras, bool modo_aleatorio);
int jugador_inicial_exp(bool modo_aleatorio, string nombres_jugadores[], int const CANT_JUGADORES);
bool fin_de_fase_exp(int estatuillas[], int const CANT_ESTATUILLAS);
void fase_expedicion(bool modo_aleatorio, string jugadores_menu[], int const CANT_JUGADORES, int& max_pdv, string& max_jugador);
void menu_jugar(int const CANT_JUGADORES, int& max_pdv, string& max_jugador);
void menu_estadisticas(int max_pdv, string max_jugador);
void menu_creditos(int max_pdv, string max_jugador);
void menu(int& max_pdv, string& max_jugador);

#endif // FUNCIONES_H