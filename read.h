/**
 * @file read.h
 * @author Fernanda Macedo de Sousa
 * @author Mariana Alencar do Vale
 * @brief Biblioteca de implementação das funções de leitura
 * @detais A biblioteca read.h contém o arquivo com a descrição das funções
 * necessárias para a leitura do arquivo .txt contendo os dados de entrada.
 * @see read.c
 */

#ifndef LeituraBibliotecacodigosprojeto4tag
#define LeituraBibliotecacodigosprojeto4tag

#include <stdio.h>
#include "graph.h"

/**
 * @brief Estrutura Linha para leitura das linhas do arquivo
 * @param ponteiro para vetor para armazenar os caracteres (char* string).
 * @param Ponteiro para próxima estrutura linha.
 */
typedef struct linha{
    char* string;
    struct linha* ponteiro;
}Linha;

/**
 * @brief Função de abrir o arquivo
 * @details Utilizada para abrir o arquivo de entrada .txt.
 * @return Um FILE* se encontrado, caso contrário retorna NULL.
 */
FILE* AbrirArquivo();

/**
 * @brief Função de fechar o arquivo
 * @details Recebe um arquivo e o fecha.
 * @param arquivo em que será aplicada a função.
 */
void FecharArquivo(FILE* arquivo);

/**
 * @brief Função para redefinir para o início do buffer novamente
 * @details reseta ponteiros igualando o ponteiro do início ao do fim.
 */
void resetarPonteiros();

/**
 * @brief Função para obter a próxima linha no buffer.
 * @details Lê a linha seguinte
 * @param char array de caracteres da linha para leitura
 * @return confirmação se tem ou não algo a ser lido, 
 * retorna 0 se há uma linha ou 1 se chegado ao final do buffer.
 */
int ProximaLinha(char linha[]);

/**
 * @brief Função para ler todo o arquivo em um buffer
 * @param arquivo lido
 */
 int fillBuffer(FILE *stream);

 /**
  * @brief Função de leitura de linhas de um arquivo
  * @return 0, caso a leitura tenha sido realizada com sucesso;
  * 1, caso contrário.
  */
int LerLinha(FILE *stream, char line[]);

/**
 * @brief Função que libera o buffer 
 */
void freeBuffer();

/**
  * @brief Função que monta o grafo
  * @details monta grafo a partir dos dados lidos do arquivo de entrada
  * @return ponteiro grafo
  */
grafo* LerGrafo();

/**
 * @brief Testa funções do grafo
 * @details Utilizada para testes das funções durante a implementação. 
 */
void Teste3();

#endif
