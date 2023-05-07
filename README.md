# Projeto Criptografia RSA

Projeto desenvolvido para a disciplina de Matemática Discreta – 2022.2, no Instituto de Computação da Universidade de Alagoas (IC/UFAL). Este README busca descrever o trabalho de forma mais técnica e voltada para o desenvolvimento. 

#### Professor
- Bruno Pimentel

#### Alunos 
- Antonio Guilherme da Silva
- Pablo Munih Silva de Carvalho
- Vívian Costa Pontes

## Sumário

Clique nos links abaixo para acessar rapidamente a seção desejada:

- [Sobre](#sobre)
- [Principais Funcionalidades](#principais-funcionalidades)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Como executar](#como-executar)

## Sobre
O projeto, desenvolvido utilizando a linguagem C, permite que o usuário realize a encriptação e desencriptação de mensagens utilizando o algoritmo RSA. Para isso, o usuário deve gerar uma chave pública, que pode ser compartilhada com outros usuários para que possam enviar mensagens criptografadas. O usuário também pode descriptografar mensagens recebidas utilizando sua chave privada.

## Principais Funcionalidades

- **Gerar Chave Pública**: Gera uma chave pública para o usuário, que pode ser compartilhada com outros usuários para que possam enviar mensagens criptografadas.

- **Encriptar Mensagem**: Encripta uma mensagem utilizando a chave pública do usuário.

- **Desencriptar Mensagem**: Desencripta uma mensagem utilizando a chave privada do usuário.

## Estrutura do Projeto

O projeto está estruturado da seguinte forma:

```
Projeto-Criptografia-RSA
│   main.c
|   makefile
└───lib
│   └───utils.c
│   └───utils.h
```

- **main.c**: Arquivo principal do projeto, contendo a função main e a lógica de execução do programa.

- **makefile**: Arquivo utilizado para compilar o projeto.

- **lib**: Pasta contendo os arquivos de biblioteca do projeto.

- **utils.c**: Arquivo contendo as funções utilitárias do projeto.

- **utils.h**: Arquivo contendo os cabeçalhos das funções utilitárias do projeto.

## Como executar

Para executar o projeto, basta executar o comando `make` na pasta raiz do projeto. Em seguida, execute o comando `./main` para executar o programa.

```
$ make
$ ./main
```

Após executar o programa, será exibido um menu com as opções disponíveis. Para selecionar uma opção, basta digitar o número correspondente e pressionar a tecla `Enter`.

```
Digite o número da opção desejada:
[1] - Gerar chave pública
[2] - Encriptar
[3] - Desencriptar
```

### Gerar Chave Pública

Para gerar uma chave pública, basta selecionar a opção `1` no menu principal. Em seguida, será solicitado que o usuário digite um número primo `p` e um número primo `q`. Após isso, será solicitado que o usuário digite um expoente `e`, que deve ser um número primo relativo a `(p-1)*(q-1)`. Por fim, um arquivo `chavespublicas.txt` será gerado na pasta raiz do projeto, contendo a chave pública gerada.

```
Digite o número da opção desejada:
[1] - Gerar chave pública
[2] - Encriptar
[3] - Desencriptar
Opção: 1
```

```
Digite o primeiro número primo (p):
7
Digite o segundo número primo (q):
13
Agora, digite um número entre 1 e 72 que não possua divisores comuns com 72:
5
```

```
Arquivo 'chavespublicas.txt' criado com sucesso!
```

### Encriptar

Para encriptar uma mensagem, basta selecionar a opção `2` no menu principal. Em seguida, será solicitado que o usuário digite a mensagem que deseja encriptar. Após isso, será solicitado que o usuário digite o módulo `n` e o expoente `e` da chave pública do destinatário. Por fim, um arquivo `textocodificado.txt` será gerado na pasta raiz do projeto, contendo a mensagem encriptada.

```
Digite o número da opção desejada:
[1] - Gerar chave pública
[2] - Encriptar
[3] - Desencriptar
Opção: 2
```

```
Digite a frase para encriptar:
teste
```

```
Digite o valor da chave pública (n):
91
Digite o valor da chave pública (e):
5
```

```
Arquivo 'textocodificado.txt' criado com sucesso!
```

### Desencriptar

Para desencriptar uma mensagem, basta selecionar a opção `3` no menu principal. Em seguida, será solicitado que o usuário digite o número primo `p` e o número primo `q` utilizados para gerar a chave pública. Após isso, será solicitado que o usuário digite o expoente `e`. Por fim, é solicitado que o usuário digite o nome do arquivo contendo a mensagem encriptada. Após isso, um arquivo `textodecodificado.txt` será gerado na pasta raiz do projeto, contendo a mensagem desencriptada.

```
Digite o número da opção desejada:
[1] - Gerar chave pública
[2] - Encriptar
[3] - Desencriptar
Opção: 3
```

```
Digite o primeiro número primo (p):
7
Digite o segundo número primo (q):
13
Digite o valor da chave pública (e):
5
```

```
Chaves privadas d: 73, n: 91
```

```
Digite o nome do arquivo que contém o texto codificado:
textocodificado.txt
```

```
Arquivo 'textodecodificado.txt' criado com sucesso!
```