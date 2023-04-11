#include <stdio.h>

int main()
{
    // Memoria para um array de caracter(string) para no max 1000 caracter
    char texto[1000]; 
    
    // O %s ê uma string até o "espaço", quando colocamos [^\n], forçamos o programa a ler até o \n
    scanf("%[^\n]s",texto); 
    
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
            printf("%d\n", valor - 63);
        // Verifica se o valor do caracter na tabela ASCII está entre "a" (97) e "z" (122)
        // Caso esteja, devemos mapear o valor para ficar entre "2" e "27" e fazemos isso subtraindo "95"
        } else if (valor >= 97 && valor <= 122) {
            printf("%d\n", valor - 95);
        // Caso o valor seja 32, sabemos que o caracter digitado é um espaço, logo deve ser mapeado para "28"
        } else if (valor == 32) { 
            printf("%d\n", 28);
        // Caso o valor seja "0", significa que o texto acabou
        } else if (valor == 0) { 
            // Quando o texto acaba, o 'break' é usado para quebrar o loop
            break;
        }
    }

    return 0;
}