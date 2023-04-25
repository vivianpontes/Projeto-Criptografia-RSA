#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

#define MAX_STRING 1000
#define MAX_CHAVE 999999999

typedef long long unsigned int big_int;

void limparTerminal();
big_int *textoParaCodificacao();
bool ehprimo(big_int numero, big_int i);
big_int inversoModulo(big_int a, big_int modulo);
big_int mdc(big_int numero1, big_int numero2);
big_int restoDaPotencia(big_int numero, big_int potencia, big_int divisor);