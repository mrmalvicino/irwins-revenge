#include <iostream>
using namespace std;

int turno_nuevo(int turno_actual, int cant_jugs);

string nombre_de_estatuilla(int numero_de_estat);

void mostrar_inventario(string jugadores_fase_exp[], int cant_jugs, int estatuillas[], int cant_ests);

void elegir_estatuillas_disponibles(int estatuillas[], int cant_ests);

int tirar_dado(int cant_caras);

int jugador_inicial_exp();

bool fin_expedicion(int estatuillas[], int cant_ests);

void fase_expedicion(string jugadores_menu[], int cant_jugs);

void menu_jugar(int cant_jugs);

void menu_estadisticas();

void menu_creditos();

void menu();