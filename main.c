#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "lib/utils.h"

void main()
{
    limparTerminal();

    /*
        Variável que guarda a opção escolhida pelo usuário
    */
    int opcaousuario;

    /*
        Pede para o usuário digitar a opção desejada
    */
    printf("Digite o número da opção desejada:\n");
    printf("[1] - Gerar chave pública\n");
    printf("[2] - Encriptar\n");
    printf("[3] - Desencriptar\n");
    printf("Opção: ");
    scanf("%d", &opcaousuario);

    limparTerminal();

    /*
        Opção 1: Gera as chaves públicas
        Passos: 
            1 - Pede para o usuário digitar dois números primos
            2 - Verifica se os números digitados são primos
            3 - Pede para o usuário digitar um número entre 1 e o valor de (p-1)*(q-1) que não possua divisores comuns com (p-1)*(q-1)
            4 - Verifica se o número digitado é válido
            5 - Salva as chaves públicas em um arquivo
    */
    if (opcaousuario == 1)
    {
        printf("Digite o primeiro número primo (p):\n");

        big_int p;
        scanf("%llu", &p);

        while (ehprimo(p, 2) == false && p > MAX_CHAVE)
        {
            limparTerminal();

            printf("O número digitado (%llu) não é primo ou é maior que %d. Por favor, digite novamente:\n", p, MAX_CHAVE);
            scanf("%llu", &p);
        }

        printf("Digite o segundo número primo (q):\n");

        big_int q;
        scanf("%llu", &q);
        
        while (ehprimo(q, 2) == false && q > MAX_CHAVE)
        {
            limparTerminal();

            printf("O número digitado (%llu) não é primo ou é maior que %d. Por favor, digite novamente:\n", q, MAX_CHAVE);
            scanf("%llu", &q);
        }

        big_int n = p * q;
        big_int phi = (p - 1) * (q - 1);

        printf("Agora, digite um número entre 1 e %llu que não possua divisores comuns com %llu:\n", phi, phi);

        big_int e;
        scanf("%llu", &e);

        while (mdc(e, phi) != 1)
        {
            limparTerminal();

            printf("O número digitado (%llu) não é válido. Por favor, digite novamente:\n", e);

            scanf("%llu", &e);
        }

        /*
            FILE: Tipo de dado para a criação de um ponteiro para arquivo
            *arquivo_chavespublicas: É um ponteiro para um arquivo que irá salvar as chaves públicas
        */
        FILE *arquivo_chavespublicas;

        /*
            fopen: Cria um arquivo com o nome "chavespublicas.txt" em modo de escrita (representado pelo "w")
            Após a criação, o ponteiro criado recebe o endereço do arquivo
        */
        arquivo_chavespublicas = fopen("chavespublicas.txt", "w");
        
        /*
            fprintf: Escreve no arquivo
            arquivo_chavespublicas: Ponteiro para o arquivo
            "Chaves públicas n: %llu, e: %llu": String que será escrita no arquivo
            n, e: Variáveis que serão substituídas na string
        */
        fprintf(arquivo_chavespublicas, "Chaves públicas n: %llu, e: %llu", n, e);
        fclose(arquivo_chavespublicas);

        printf("Arquivo 'chavespublicas.txt' criado com sucesso!\n");
    }
    /*
        Opção 2: Encripta o texto
        Passos:
            1 - Pede para o usuário digitar o texto que será encriptado
            2 - Converte o texto para um array de números
            3 - Pede para o usuário digitar as chaves públicas
            4 - Encripta o texto e salva em um arquivo
    */
    else if (opcaousuario == 2)
    {
        printf("Digite a frase para criptografar:\n");
        
        // Limpa o buffer do teclado
        getchar(); 

        // Cria um ponteiro para um inteiro
        big_int *codificacao;
        // Atribui ao ponteiro o primeiro endereço de memória do array codificação
        codificacao = textoParaCodificacao();

        /*
            FILE: Tipo de dado para a criação de um ponteiro para arquivo
            *arquivo_textocodificado: É um ponteiro para um arquivo que irá salvar o texto codificado
        */
        FILE *arquivo_textocodificado;

        /*
            fopen: Cria um arquivo com o nome "textocodificado.txt" em modo de escrita (representado pelo "w")
            Após a criação, o ponteiro criado recebe o endereço do arquivo
        */
        arquivo_textocodificado = fopen("textocodificado.txt", "w");

        // Memoria para o indice do array
        big_int i;
        big_int e, n;

        printf("Digite a chave pública e:\n");
        scanf("%llu", &e);
        printf("Digite a chave pública n:\n");
        scanf("%llu", &n);

        /* 
            Loop que começa em 0 e vai até o valor do indice menor que MAX_STRING.
            i = 0; - inicio o 'i' valendo zero
            i < MAX_STRING; - condição para o loop continuar acontecendo
            i++ - incremento que acontece após o final de cada loop 
        */
        for (i = 0; i < MAX_STRING; i++)
        {
            // Pega o valor atual do array
            int valor = codificacao[i];

            // Verifica se é o final da codificação (valor -1)
            if (valor != -1)
            {
                // Se não for, ele escreve o valor codificado no arquivo
                fprintf(arquivo_textocodificado, "%llu ", restoDaPotencia(valor, e, n));
            }
            else
            {
                // Se for, ele finaliza o loop e escreve um fim de linha (\n)
                fprintf(arquivo_textocodificado, "\n");
                break;
            }
        }

        fclose(arquivo_textocodificado);

        printf("Arquivo 'textocodificado.txt' criado com sucesso!\n");
    }
    /*
        Opção 3: Decripta o texto
        Passos:
            1 - Pede para o usuário digitar as chaves privadas
            2 - Decripta o texto e salva em um arquivo
    */
    else if (opcaousuario == 3)
    {
        printf("Digite o valor de p: ");

        big_int p;
        scanf("%llu", &p);

        printf("Digite o valor de q: ");

        big_int q;
        scanf("%llu", &q);

        printf("Digite o valor de e: ");

        big_int e;
        scanf("%llu", &e);

        big_int phi = (p - 1) * (q - 1);
        big_int d = inversoModulo(e, phi);
        big_int n = p * q;

        printf("d: %llu, n: %llu\n", d, n);

        char nome_arquivo[MAX_STRING];

        printf("Digite o arquivo de texto a ser decodificado: ");
        scanf("%s", nome_arquivo);

        FILE *arquivo_textocodificado;
        arquivo_textocodificado = fopen(nome_arquivo, "r");

        if (arquivo_textocodificado == NULL)
        {
            printf("Ocorreu um erro ao abrir o arquivo.\n");
            return;
        }

        big_int numbers[MAX_STRING];
        big_int num, i = 0;

        while (fscanf(arquivo_textocodificado, "%llu", &num) != EOF)
        {
            numbers[i++] = num;
        }

        fclose(arquivo_textocodificado);

        FILE *arquivo_textodecodificado;
        arquivo_textodecodificado = fopen("textodecodificado.txt", "w");

        for (big_int j = 0; j < i; j++)
        {
            big_int valor = restoDaPotencia(numbers[j], d, n);

            if (valor == 28)
            {
                fprintf(arquivo_textocodificado, "%c", 32);
            }
            else
            {
                fprintf(arquivo_textocodificado, "%c", (int) (valor + 95));
            }
        }

        fclose(arquivo_textodecodificado);
        
        printf("Arquivo 'textodecodificado.txt' criado com sucesso!\n");
    }
}