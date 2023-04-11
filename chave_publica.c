#include <stdio.h>
#include <stdbool.h>
#include <math.h>
 
//FUNÇÃO PARA FAZER O MDC DE "e" E "Tangente de N"
int mdc (int numero1, int numero2)
{
    if (numero2 == 0) // condição de parada: quando um número for 0, o mdc é o outro número
    {
        return numero1;
    }
    else // caso nenhum numero não seja 0, ainda, faço o mdc do menor numero com o resto da divisão anterior (maior - menor)
    {
        return mdc (numero2, numero1 % numero2);
    }
}

 //FUNÇÃO PARA VERIFICAR SE O NUMERO É PRIMO
bool ehprimo(long long unsigned n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (long long unsigned i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
 
int main()
{
    double p, q, n, e;
    int opcaousuario;
    
    // Pede para o usuário digitar uma das opções abaixo:
    printf("Digite a opção:\n 1 - Gerar chave pública\n 2 - Encriptar\n 3 - Desencriptar\n");
    scanf("%d", &opcaousuario);

    if (opcaousuario == 1) { //Gerar chave pública
    
        printf("Digite dois números primos de pelo menos dois digitos:\n");
        scanf("%lf %lf", &p, &q);

        while (ehprimo(p) == false || ehprimo(q) == false)
        {
            printf("Um dos números não é primo. Por favor, digite novamente:\n");
            scanf("%lf %lf", &p, &q);
        }
        
        n = p*q;
        int TangenteDeN = (p-1) * (q-1);

        printf("Agora, digite um número entre 1 e %d:\n", TangenteDeN);
        scanf("%lf", &e);
        
        while (mdc(e, TangenteDeN) != 1)
        {
            printf("Esse número tem mais de um divisor comum. Por favor, digite outro número:\n");
            scanf("%lf", &e);
        }

        /*Salve, no diretório de execução do programa, um arquivo txt com os dois números que formam a chave pública.
        As chaves públicas são: “n” e “e” */

    } else if (opcaousuario == 2) {
        //Encriptar;
    } else if (opcaousuario == 3) {
        //Desencriptar
    } else {
        //printf(“Opção inválida\n”);
    }

    return 0;
}
