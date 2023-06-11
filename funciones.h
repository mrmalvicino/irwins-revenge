#include <iostream>
using namespace std;

int turno_nuevo(int turno_actual);
string nombre_de_estatuilla(int numero_de_estat);
void mostrar_inventario(string jugador1, string jugador2, int estatuillas[], int CANT_EST);
void elegir_estatuilla(int estatuillas[], int CANT_EST);
int tirar_dado(int caras);
int jugador_inicial_exp();
bool fin_expedicion(int estatuillas[], int CANT_EST);
void fase_expedicion(string jugadores[], int cant_jugadores);
void menu_jugar(int cant_jugadores);
void menu_estadisticas();
void menu_creditos();
void menu();