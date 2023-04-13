#include <stdio.h>

int* textoParaCodificacao()
{
    // Memoria para um array de caracter(string) para no max 1000 caracter
    char texto[1000]; 
    
    // O %s ê uma string até o "espaço", quando colocamos [^\n], forçamos o programa a ler até o \n
    scanf("%[^\n]s",texto); 

    // Memoria para salvar a codificao do texto, a variável é estática, pois, a linguagem c não permite o retorno de arrays locais
    // Uma variável estática preserva seu valor mesmo após a função terminar de ser executada, permitindo assim retornar o valor
    static int codificacao[1000];
    
    // Memoria para o indice do array
    int i;

    /* Loop que começa em 0 e vai até o valor do indice menor que 1000.
        i = 0; - inicio o 'i' valendo zero
        i < 1000; - condição para o loop continuar acontecendo
        i++ - incremento que acontece após o final de cada loop */
    for(i = 0; i < 1000; i++) {
        // Mapeia o caracter atual para um valor inteiro baseado na tabela ASCII
        int valor = texto[i];
        
        // Verifica se o valor do caracter na tabela ASCII está entre "A" (65) e "Z" (90)
        // Caso esteja, devemos mapear o valor para ficar entre "2" e "27" e fazemos isso subtraindo "63"
        if (valor >= 65 && valor <= 90) {
            // O valor mapeado é salvo no array de codificação
            codificacao[i] = valor - 63;
        // Verifica se o valor do caracter na tabela ASCII está entre "a" (97) e "z" (122)
        // Caso esteja, devemos mapear o valor para ficar entre "2" e "27" e fazemos isso subtraindo "95"
        } else if (valor >= 97 && valor <= 122) {
            // O valor mapeado é salvo no array de codificação
            codificacao[i] = valor - 95;
        // Caso o valor seja 32, sabemos que o caracter digitado é um espaço, logo deve ser mapeado para "28"
        } else if (valor == 32) {
            // O valor mapeado é salvo no array de codificação
            codificacao[i] = 28;
        // Caso o valor seja "0", significa que o texto acabou
        } else if (valor == 0) {
            // Quando o texto acaba, no array de codificação é salvo -1, para que seja possível identificarmos onde acaba a codificação
            codificacao[i] = -1;
            // Quando o texto acaba, o 'break' é usado para quebrar o loop
            break;
        }
    }

    // Retorna o ponteiro para o array codificação
    return codificacao;
}

int main()
{
    printf("Digite a frase para criptografar:\n");

    // Cria um ponteiro para um inteiro
    int *codificacao;
    // Atribui ao ponteiro o primeiro endereço de memória do array codificação
    codificacao = textoParaCodificacao();

    // FILE: Tipo de dado para a criação de um ponteiro para arquivo
    // *arquivo_textocodificado: É um ponteiro para um arquivo que irá salvar o texto codificado
    FILE *arquivo_textocodificado;

    // fopen: Cria um arquivo com o nome "textocodificado.txt" em modo de escrita (representado pelo "w")
    // Após a criação, o ponteiro criado recebe o endereço do arquivo
    arquivo_textocodificado = fopen("textocodificado.txt", "w");

    // Memoria para o indice do array
    int i;

    /* Loop que começa em 0 e vai até o valor do indice menor que 1000.
       i = 0; - inicio o 'i' valendo zero
       i < 1000; - condição para o loop continuar acontecendo
       i++ - incremento que acontece após o final de cada loop */
    for (i = 0; i < 1000; i++) {
        // Pega o valor atual do array
        int valor = codificacao[i];

        // Verifica se é o final da codificação (valor -1)
        if (valor != -1) {
            // Se não for, ele escreve no arquivo o caractere criptografado
            /*(int) fmod(pow(valor, e), n)
            (int): faz uma conversão do valor "double" para inteiro
            fmod: realiza operação de modulo entre o valor do primeiro parametro e do segundo (ex: fmod(a,b) = a mod b)
            pow: realiza o calculo da exponencial entre o valor do primeiro parametro e do segundo (ex: pow(valor, e) = valor^e)*/
            fprintf(arquivo_textocodificado, "%d ", (int) fmod(pow(valor, e), n));
        } else {
            // Se for, ele finaliza o loop e escreve um fim de linha (\n)
            fprintf(arquivo_textocodificado, "\n");
            break;
        }
    }

    return 0;
}