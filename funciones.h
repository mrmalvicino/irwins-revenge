#include <iostream>
using namespace std;

void puntos_de_victoria(string jugadores_final[], int const CANT_JUGADORES, int estatuillas[], int const CANT_ESTATUILLAS, int ganador_fase_fin, int intentos[][5]);
int jugador_inicial_final(int estatuillas[], int const CANT_ESTATUILLAS, int const CANT_JUGADORES);
bool fin_de_fase_fin(int dados_ordenados[], int cant_dds, int turno_actual, int portador_de_medusa, int portador_de_salamandra);
void fase_final(string jugadores_fase_exp[], int const CANT_JUGADORES, int estatuillas[], int const CANT_ESTATUILLAS, int intentos[][5]);
bool arena_cangrejo(int dado1, int dado2, int dado3);
bool tierra_hormiga(int dado1, int dado2, int dado3);
bool agua_medusa(int dado1, int dado2, int dado3);
bool aire_aguila(int dado1, int dado2, int dado3);
bool fuego_salamandra(int dado1, int dado2, int dado3);
bool guardar_inventario(int dados_exp[], int objetivos[], int turno_actual);
int turno_nuevo(int turno_actual, int const CANT_JUGADORES);
string nombre_de_estatuilla(int numero_de_estat);
void mostrar_inventario(string jugadores_fase_exp[], int const CANT_JUGADORES, int estatuillas[], int const CANT_ESTATUILLAS);
void elegir_estatuillas_disponibles(int estatuillas[], int const CANT_ESTATUILLAS);
int tirar_dado(int cant_caras);
int jugador_inicial_exp();
bool fin_de_fase_exp(int estatuillas[], int const CANT_ESTATUILLAS);
void fase_expedicion(string jugadores_menu[], int const CANT_JUGADORES);
void menu_jugar(int const CANT_JUGADORES);
void menu_estadisticas();
void menu_creditos();
void menu();