// Arquivo principal do projeto, integrando todas as funções feitas até então

#include <stdio.h>
#include <stdbool.h>
#include <math.h>



int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
    {
        return 0;
    }

    while (a > 1)
    {
        // q é o quociente da divisão inteira de 'a' por 'm'
        int q = a / m;

        int t = m;

        // atualiza 'm' como o resto da divisão inteira de 'a' por 'm'
        m = a % m, a = t;
        t = y;

        // atualiza 'y' como 'x' menos o quociente da divisão inteira de 'a' por 'm' vezes 'y'
        y = x - q * y;

        x = t;
    }

    // se 'x' é negativo, adiciona 'm0' para torná-lo positivo
    if (x < 0)
    {
        x += m0;
    }

    return x;
}


int restoDaPotencia(int numero, int potencia, int divisor)
{
    int resultado = 1;
    while (potencia > 0)
    {
        if (potencia % 2 == 1)
        {
            resultado = (resultado * numero) % divisor;
        }
        numero = (numero * numero) % divisor;
        potencia /= 2;
    }
    return resultado;
}

int *textoParaCodificacao()
{
    // Memoria para um array de caracter(string) para no max 1000 caracter
    char texto[1000];

    // O %s ê uma string até o "espaço", quando colocamos [^\n], forçamos o programa a ler até o \n
    scanf("%[^\n]", texto);

    // Memoria para salvar a codificao do texto, a variável é estática, pois, a linguagem c não permite o retorno de arrays locais
    // Uma variável estática preserva seu valor mesmo após a função terminar de ser executada, permitindo assim retornar o valor
    static int codificacao[1000];

    // Memoria para o indice do array
    int i;

    /* Loop que começa em 0 e vai até o valor do indice menor que 1000.
        i = 0; - inicio o 'i' valendo zero
        i < 1000; - condição para o loop continuar acontecendo
        i++ - incremento que acontece após o final de cada loop */
    for (i = 0; i < 1000; i++)
    {
        // Mapeia o caracter atual para um valor inteiro baseado na tabela ASCII
        int valor = texto[i];

        // Verifica se o valor do caracter na tabela ASCII está entre "A" (65) e "Z" (90)
        // Caso esteja, devemos mapear o valor para ficar entre "2" e "27" e fazemos isso subtraindo "63"
        if (valor >= 65 && valor <= 90)
        {
            // O valor mapeado é salvo no array de codificação
            codificacao[i] = valor - 63;
            // Verifica se o valor do caracter na tabela ASCII está entre "a" (97) e "z" (122)
            // Caso esteja, devemos mapear o valor para ficar entre "2" e "27" e fazemos isso subtraindo "95"
        }
        else if (valor >= 97 && valor <= 122)
        {
            // O valor mapeado é salvo no array de codificação
            codificacao[i] = valor - 95;
            // Caso o valor seja 32, sabemos que o caracter digitado é um espaço, logo deve ser mapeado para "28"
        }
        else if (valor == 32)
        {
            // O valor mapeado é salvo no array de codificação
            codificacao[i] = 28;
            // Caso o valor seja "0", significa que o texto acabou
        }
        else if (valor == 0)
        {
            // Quando o texto acaba, no array de codificação é salvo -1, para que seja possível identificarmos onde acaba a codificação
            codificacao[i] = -1;
            // Quando o texto acaba, o 'break' é usado para quebrar o loop
            break;
        }
    }

    // Retorna o ponteiro para o array codificação
    return codificacao;
}

// FUNÇÃO PARA FAZER O MDC DE "e" E "Tangente de N"
int mdc(int numero1, int numero2)
{
    if (numero2 == 0) // condição de parada: quando um número for 0, o mdc é o outro número
    {
        return numero1;
    }
    else // caso nenhum numero não seja 0, ainda, faço o mdc do menor numero com o resto da divisão anterior (maior - menor)
    {
        return mdc(numero2, numero1 % numero2);
    }
}

// FUNÇÃO PARA VERIFICAR SE O NUMERO É PRIMO
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

    if (opcaousuario == 1)
    { // Gerar chave pública

        printf("Digite dois números primos de pelo menos dois digitos:\n");
        scanf("%lf %lf", &p, &q);

        while (ehprimo(p) == false || ehprimo(q) == false)
        {
            printf("Um dos números não é primo. Por favor, digite novamente:\n");
            scanf("%lf %lf", &p, &q);
        }

        n = p * q;
        int TangenteDeN = (p - 1) * (q - 1);

        printf("Agora, digite um número entre 1 e %d que não possua divisores comuns com %d:\n", TangenteDeN, TangenteDeN);
        scanf("%lf", &e);

        while (mdc(e, TangenteDeN) != 1)
        {
            printf("Esse número tem mais de um divisor comum. Por favor, digite outro número:\n");
            scanf("%lf", &e);
        }

        // FILE: Tipo de dado para a criação de um ponteiro para arquivo
        // *arquivo_chavespublicas: É um ponteiro para um arquivo que irá salvar as chaves públicas
        FILE *arquivo_chavespublicas;

        // fopen: Cria um arquivo com o nome "chavespublicas.txt" em modo de escrita (representado pelo "w")
        // Após a criação, o ponteiro criado recebe o endereço do arquivo
        arquivo_chavespublicas = fopen("chavespublicas.txt", "w");
        // fprint: Escreve no arquivo criado o texto passado no segundo parametro.
        fprintf(arquivo_chavespublicas, "Chaves públicas n: %0.0lf e:%0.0lf", n, e);
        fclose(arquivo_chavespublicas);
    }
    else if (opcaousuario == 2)
    { // Encriptar;
        printf("Digite a frase para criptografar:\n");

        long long unsigned int teste;
        scanf("%llu", &teste);

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
        long long unsigned int i;
        long long unsigned int e, n;
        printf("Digite a chave pública e:\n");
        scanf("%lld", &e);
        printf("Digite a chave pública n:\n");
        scanf("%lld", &n);

        //avisa que o texto codificado foi gerado
        printf("O texto codificado foi gerado\n");


        /* Loop que começa em 0 e vai até o valor do indice menor que 1000.
        i = 0; - inicio o 'i' valendo zero
        i < 1000; - condição para o loop continuar acontecendo
        i++ - incremento que acontece após o final de cada loop */
        for (i = 0; i < 1000; i++)
        {
            // Pega o valor atual do array
            int valor = codificacao[i];

            // Verifica se é o final da codificação (valor -1)
            if (valor != -1)
            {
                //
                fprintf(arquivo_textocodificado, "%d ", restoDaPotencia(valor, e, n));
            }
            else
            {
                // Se for, ele finaliza o loop e escreve um fim de linha (\n)
                fprintf(arquivo_textocodificado, "\n");
                break;
            }
        }
    }
    else if (opcaousuario == 3)
    {
        long long unsigned int p, q, e;
        printf("Digite o valor de p: ");
        scanf("%llu", &p);
        printf("Digite o valor de q: ");
        scanf("%llu", &q);
        printf("Digite o valor de e: ");
        scanf("%llu", &e);
        long long unsigned int phi = (p - 1) * (q - 1);
        char nome_arquivo[100];
        long long unsigned int d = modInverse(e, phi);
        long long unsigned int n = p * q;
        printf("Digite o arquivo de texto a ser decodificado: ");
        scanf("%s", nome_arquivo);

        FILE *arquivo_textocodificado;
        arquivo_textocodificado = fopen(nome_arquivo, "r");

        if (arquivo_textocodificado == NULL)
        {
            printf("Erro ao abrir o arquivo\n");
            return 0;
        }

        long long unsigned int numbers[1000] = {-99};
        long long unsigned int num, i = 0;

        while (fscanf(arquivo_textocodificado, "%lld", &num) == 1)
            
        {
            numbers[i++] = num;
        }

        fclose(arquivo_textocodificado);

        FILE *arquivo_textodecodificado;
        arquivo_textodecodificado = fopen("textodecodificado.txt", "w");
        for (int j = 0; j < i; j++)
        {
            int valor = restoDaPotencia(numbers[j], d, n);
            if (valor == 28)
                fprintf(arquivo_textocodificado, "%c", 32);
            else
            {
                fprintf(arquivo_textocodificado, "%c", valor + 95);
            }
        }
        printf("O arquivo foi decodificado com sucesso!\n");

        return 0;
    }
}
