#ifndef SEGURIDAD_H
#define SEGURIDAD_H

#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;

string Leer(string nombre, int tipo);
    /* Esta funcion se encargara de leer un archivo. */
void Escribir(string nombre, string texto);
    /* Esta funcion se encargara de escribir un archivo. */
string Cabin(string texto);
    /* Esta funcion se encargara de convertir una cadena de caracteres a su equivalente en binario. */
string Binca(string texto);
    /* Esta funcion se encargara de covertir un texto en binario a su equivalente en caracteres. */
string Codificar1(string textobinario, int semilla);
    /* Esta funcion codificara un texto binario usando el primer metodo sugerido en el PDF. */
string Decodificar1(string codificado, int semilla);
    /* Esta funcion se encargara de decodificar un texto binario mediante el primer metodo sugerido en el PDF. */
string Invertir(string binario, int num);
    /* Esta funcion se encargara de codificar un bloque de n bits. */
long Contar1y0(string binario, char numero);
    /* Esta funcion se encargara de contar cuantos 1s y 0s hay en un bloque de n bits. */
string reverse(string cadena);
    /* Esta funcion se encargara de invertir una cadena string. */

#endif // SEGURIDAD_H
