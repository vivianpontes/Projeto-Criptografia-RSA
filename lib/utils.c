#include "utils.h"

/*
 * Função que limpa o terminal
 * params: não possui parâmetros
 * return: não possui retorno
 */
void limparTerminal()
{
    system("clear");
}

/*
 * Função que calcula o resto da potência de um número
 * params: não possui parâmetros
 * return: um ponteiro para um array de big_int com a codificação do texto
 */
big_int *textoParaCodificacao()
{
    /*
        Memoria para um array de caracter(string) para no max MAX_STRING caracter
    */
    char texto[MAX_STRING];

    /*
        O %s ê uma string até o "espaço", quando colocamos [^\n], forçamos o programa a ler até o \n
    */
    scanf("%[^\n]", texto);

    /* 
        Memoria para salvar a codificao do texto, a variável é estática, pois, a linguagem c não permite o retorno de arrays locais
        Uma variável estática preserva seu valor mesmo após a função terminar de ser executada, permitindo assim retornar o valor
    */
    static big_int codificacao[MAX_STRING];

    /*
        Memoria para o indice do array
    */
    big_int i;

    /* 
        Loop que começa em 0 e vai até o valor do indice menor que MAX_STRING.
        i = 0; - inicio o 'i' valendo zero
        i < MAX_STRING; - condição para o loop continuar acontecendo
        i++ - incremento que acontece após o final de cada loop
    */
    for (i = 0; i < MAX_STRING; i++)
    {
        /*
            Mapeia o caracter atual para um valor inteiro baseado na tabela ASCII
        */
        big_int valor = texto[i];

        /*
            Verifica se o valor do caracter na tabela ASCII está entre "A" (65) e "Z" (90)
            Caso esteja, devemos mapear o valor para ficar entre "2" e "27" e fazemos isso subtraindo "63"
        */
        if (valor >= 65 && valor <= 90)
        {
            /*
                O valor mapeado é salvo no array de codificação
            */
            codificacao[i] = valor - 63;
        }
        /*
            Verifica se o valor do caracter na tabela ASCII está entre "a" (97) e "z" (122)
            Caso esteja, devemos mapear o valor para ficar entre "2" e "27" e fazemos isso subtraindo "95"
        */
        else if (valor >= 97 && valor <= 122)
        {
            /*
                O valor mapeado é salvo no array de codificação
            */
            codificacao[i] = valor - 95;
        }
        /*
            Caso o valor seja 32, sabemos que o caracter digitado é um espaço, logo deve ser mapeado para "28"
        */
        else if (valor == 32)
        {
            /*
                O valor mapeado é salvo no array de codificação
            */
            codificacao[i] = 28;
        }
        /*
            Caso o valor seja 0, sabemos que o texto acabou, logo devemos parar de ler o texto
        */
        else if (valor == 0)
        {
            /*
                O valor -1 é salvo no array de codificação, pois, ele é usado para indicar o fim do texto
            */
            codificacao[i] = -1;
            /*
                O loop é parado
            */
            break;
        }
    }

    /*
        Retorna o ponteiro para o array codificação
    */
    return codificacao;
}

/*
 * Função que verifica se um número é primo
 * params: big_int n - número a ser verificado
 * return: bool - true se for primo, false se não for primo 
 */
bool ehprimo(big_int numero, big_int i)
{
    /*
        Verifica se o número é 0 ou 1, pois, eles não são primos
        Verifica se o número é igual ao divisor atual, pois, se for, ele é primo
        Verifica se o resto da divisão do número pelo divisor atual é 0, pois, se for, ele não é primo
    */
    if (numero == 0 || numero == 1)
        return false;
    if (numero == i)
        return true;
    if (numero % i == 0)
        return false;

    return ehprimo(numero, i + 1);
}

/*
 * Função que calcula o inverso modular de um número
 * params: big_int a - número a ser calculado o inverso modular e big_int m - número que será usado como módulo
 * return: big_int - o inverso modular do número
 */
big_int inversoModulo(big_int a, big_int modulo)
{
    /*
        Loop que começa em 1 e vai até o valor do indice menor que m.
        x = 1; - inicio o 'x' valendo um
        x < m; - condição para o loop continuar acontecendo
        x++ - incremento que acontece após o final de cada loop
    */
    for (big_int x = 1; x < modulo; x++)
    {
        /*
            Verifica se o resto da divisão entre o número e o módulo é igual a 1
            Caso seja, o número é o inverso modular do número
        */
        if (((a % modulo) * (x % modulo)) % modulo == 1)
        {
            return x;
        }
    }
}

/*
 * Função que calcula o mdc de dois números
 * params: big_int numero1 - primeiro número e big_int numero2 - segundo número
 * return: big_int - o mdc dos dois números
 */
big_int mdc(big_int numero1, big_int numero2)
{
    /*
        Verifica se o segundo número é 0, pois, se for, o mdc é o primeiro número
    */
    if (numero2 == 0)
    {
        return numero1;
    }
    else
    {
        /*
            Caso o segundo número não seja 0, o mdc é calculado novamente, porém, o primeiro número é o segundo número
            e o segundo número é o resto da divisão entre o primeiro número e o segundo número
        */
        return mdc(numero2, numero1 % numero2);
    }
}

/*
 * Função que calcula o resto da potência de um número
 * params: big_int numero - número que será calculado o resto da potência, big_int potencia - potência e big_int divisor - divisor
 * return: big_int - o resto da potência do número
 */
big_int restoDaPotencia(big_int numero, big_int potencia, big_int divisor)
{
    /*
        Variável que armazena o resultado da potência
    */
    big_int resultado = 1;

    /*
        Loop que começa em 0 e vai até o valor do indice menor que a potência.
        i = 0; - inicio o 'i' valendo zero
        i < potencia; - condição para o loop continuar acontecendo
        i++ - incremento que acontece após o final de cada loop
    */
    while (potencia > 0)
    {
        /*
            Verifica se o resto da divisão entre a potência e 2 é igual a 1
            Caso seja, o resultado é multiplicado pelo número e depois é feito o resto da divisão entre o resultado e o divisor
        */
        if (potencia % 2 == 1)
        {
            resultado = (resultado * numero) % divisor;
        }

        /*
            O número é multiplicado por ele mesmo e depois é feito o resto da divisão entre o número e o divisor
            A potência é dividida por 2
        */
        numero = (numero * numero) % divisor;
        potencia /= 2;
    }

    return resultado;
}