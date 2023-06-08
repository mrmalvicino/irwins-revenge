# Irwin's Revenge

Irwin's Revenge es un juego de dados de dos jugadores en el que intervienen el azar y la astucia.
El objetivo general del juego es ganar la Fase Final y sumar la mayor cantidad de puntos de victoria. La suma de este puntaje depende de diferentes situaciones que se pueden dar en el juego y que más adelante se explicarán.

El juego se divide en dos fases que llamaremos Fase de expedición y Fase final. Obviamente, la fase de expedición sucede primero y luego comienza la fase final. La Fase de Expedición proporcionará elementos que se utilizarán en la Fase Final por lo que ambas son muy importantes.

Antes de comenzar la fase de expedición los jugadores deberán tirar un dado de diez caras. Quien obtenga el dado menor comienza. Si ambos obtuvieron el mismo número deberán tirar de nuevo hasta que alguno de ellos obtenga el dado más chico.

## Fase de expedición

Durante la Fase de Expedición el objetivo es obtener la mayor cantidad de estatuillas. Son cinco en total y están relacionados a cinco elementos del Planeta Tierra. Los elementos, que en el juego también son conocidos como niveles, son: Arena, Tierra, Agua, Aire y Fuego.

Las estatuillas de cada elemento son:
- Arena: Cangrejo
- Tierra: Hormiga
- Agua: Medusa
- Aire: Águila
- Fuego: Salamandra

En la fase de expedición, cada jugador va alternando de a un turno a la vez en el que deben primero elegir verbalmente qué estatuilla desean obtener. Ambos jugadores pueden elegir la misma estatuilla. En el caso que el primero en lanzar obtenga la estatuilla y, por lo tanto, se la quede. El otro jugador debe anunciar verbalmente otra estatuilla antes de lanzar.

Luego de elegir la estatuilla por la que en ese turno jugarán, deberán lanzar dos dados de 10 caras (salvo excepción de maldición de la salamandra) y la obtención de la estatuilla se determina a partir de una serie de reglas. Si el jugador obtiene la estatuilla, se la queda y ya no puede perderla. La estatuilla le proporcionará al jugador una bendición en la Fase Final y una maldición en la Fase de Expedición (que puede perjudicarlo o bien beneficiar al rival).

## Las estatuillas

### Estatuilla del cangrejo:
- Obtención: Uno de sus dados debe ser par y otro de sus dados impar.
- Bendición (En fase final): Podrá lanzar los dados dos veces en el primer tiro de la fase final.
- Maldición (En fase expedición): El rival tira un dado de diez caras y el valor obtenido son los puntos de victoria que le descuenta al portador de la estatuilla al final de la partida.

### Estatuilla de la hormiga:
- Obtención: Al menos dos dados deben ser menores a 5.
- Bendición (En fase final): Antes de empezar la fase final el portador de la estatuilla puede elegir un número del 1 al 6. Luego, en cada tiro puede optar por elegir uno de los cinco dados del lanzamiento y reemplazarlo por el número elegido.
- Maldición (En fase expedición): El rival tira dos dados de diez caras y el valor obtenido son los puntos de victoria que le descuenta al portador de la estatuilla al final de la partida.

### Estatuilla de la medusa:
- Obtención: La suma de dos de los dados lanzados debe dar exactamente siete.
- Bendición (En fase final): Permite ganar el desafío de la Fase Final también con la obtención de 5 dados iguales.
- Maldición (En fase expedición): El portador de la estatuilla debe esperar 3 turnos sin lanzar dados para seguir la Fase de Expedición.

### Estatuilla del águila:
- Obtención: Dos de los dados lanzados deberán devolver los números 1 y 10.
- Bendición (En fase final): En cada tirada de la Fase Final el portador de la estatuilla podrá elegir un dado y modificar su número a su antojo.
- Maldición (En fase expedición): El rival tira dos veces por turno durante el resto de la Fase de Expedición.

### Estatuilla de la salamandra:
- Obtención: Los dados lanzados deben ser consecutivos. Por ejemplo: (1 y 2) (2 y 3) (9 y 10).
- Bendición (En fase final): El portador de la estatuilla podrá ganar la fase final con una escalera de 4 dados consecutivos entre 5 dados lanzados.
- Maldición (En fase expedición): El rival juega con tres dados durante el resto de la Fase de Expedición.

La Fase de Expedición termina cuando no quedan estatuillas en juego. A partir de ese momento, comienza la Fase Final siendo el primero en tirar aquel jugador que haya obtenido más estatuillas.

## Fase final
La Fase Final es quien determina al ganador del juego. En esta fase se utilizan 5 dados de 6 caras. Ganará la fase final aquel jugador que primero obtenga una escalera. La escalera es una tirada en la que todos los dados son correlativos. Por ejemplo:
- 1, 2, 3, 4, 5
- 2, 3, 4, 5, 6

Cabe aclarar que el orden de los dados no es importante para completar el hito de la Fase Final por lo que los siguientes lanzamientos también son exitosos:

- 2, 3, 5, 1, 4
- 6, 2, 5, 4, 3

Las únicas excepciones a las reglas de victoria en la fase final mencionadas anteriormente son las siguientes:

- Quien tenga la estatuilla de la medusa podrá ganar también con la obtención de 5 dados iguales. Por ejemplo: (1, 1, 1, 1, 1); (3, 3, 3, 3, 3); etc.

- Quien tenga la estatuilla de la salamandra podrá ganar con una escalera más corta. Sólo 4 de los 5 dados deberán ser correlativos. Ejemplos de lanzamientos exitosos podrían ser: (1, 2, 3, 4, 1); (2, 3, 4, 5, 2); (3, 4, 5, 6, 1); etc.

Una vez finalizada la partida se deben computar los Puntos de Victoria que se especifican a continuación:

| Puntos de victoria | Hito          | Descripción                                                |
|--------------------|---------------|------------------------------------------------------------|
| +5                 | Estatuilla    | Obtener una estatuilla                                     |
| +10                | Estatuilla ++ | Obtiene una estatuilla en el primer intento por obtenerla  |
| +15                | Ganador       | Ganador de la Fase Final                                   |
| +50                | Ganador ++    | Ganador de la Fase Final sin estatuillas                   |
| -3                 | Estatuilla -  | Rival obtiene una estatuilla                               |
| -1                 | Lanzamiento   | Lanzamiento en la fase final                               |

## Créditos

Programa desarrollado como trabajo práctico de la materia Laboratorio de Computación 1 de la carrera Tecnicatura Universitaria en Programación en la UTN.

- Juego inventado por Gonzalo Ligero - [gonzalo.ligero@alumnos.frgp.utn.edu.ar](gonzalo.ligero@alumnos.frgp.utn.edu.ar)
- Reglamento adaptado para TP por Gonzalo Ligero y Angel Simón.