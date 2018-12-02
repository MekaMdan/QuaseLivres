/**
 * @file read.c
 * @author Fernanda Macedo de Sousa
 * @author Mariana Alencar do Vale
 * @brief Arquivo de implementação das funções de leitura
 * @details O arquivo contém a implementação das funções necessárias para a
 * leitura do arquivo .txt contendo os dados de entrada.
 * @see read.h
 */
#include "read.h"
#include "graph.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMANHO_LINHA 1000

Linha* Primeiro;
Linha* Atual;

/**
 * @brief Função de abrir o arquivo
 * @details Utilizada para abrir o arquivo de entrada .txt.
 * @return Um FILE* se encontrado, caso contrário retorna NULL.
 */
FILE* AbrirArquivo(){
      FILE* arquivo;
      char buff[TAMANHO_LINHA];

      arquivo = fopen("email-Eu-core.txt","r");
      if (!arquivo) return NULL;
      return arquivo;
}

/**
 * @brief Função de fechar o arquivo
 * @details Recebe um arquivo e o fecha.
 * @param arquivo em que será aplicada a função.
 */
void FecharArquivo(FILE* arquivo){
      fclose(arquivo);
}

/**
 * @brief Função para redefinir para o início do buffer novamente
 * @details reseta ponteiros igualando o ponteiro do início ao do fim.
 */
void resetarPonteiros(){
    Atual = Primeiro;
}

/**
 * @brief Função para obter a próxima linha no buffer.
 * @details Lê a linha seguinte
 * @param char array de caracteres da linha para leitura
 * @return confirmação se tem ou não algo a ser lido,
 * retorna 0 se há uma linha ou 1 se chegado ao final do buffer.
 */
int ProximaLinha(char linha[TAMANHO_LINHA]){
    if(Atual==NULL) return 1;
    strcpy(linha,Atual->string);
    Atual = Atual->ponteiro;
    return 0;
}

/**
 * @brief Função para ler todo o arquivo em um buffer
 * @param arquivo lido
 */
int fillBuffer(FILE *stream){
    int tam;
    char linha[TAMANHO_LINHA];
    Linha* anterior;

    if(LerLinha(stream,linha)!=0){
        Primeiro = NULL; /* indica que o buffer esta vazio*/
        return 1;
    }
    tam = strlen(linha)+1;
    Primeiro = malloc(sizeof(Linha));
    Primeiro->string = malloc(tam*sizeof(char));
    strcpy(Primeiro->string, linha);

    anterior = Primeiro;
    while(LerLinha(stream,linha)==0){
      tam = strlen(linha)+1;
      anterior->ponteiro = malloc(sizeof(Linha));
      anterior = anterior->ponteiro;
      anterior->string = malloc(tam*sizeof(char));
      strcpy(anterior->string, linha);
    }
    anterior->ponteiro = NULL;

    return 0;
 }

 /**
  * @brief Função de leitura de linhas de um arquivo
  * @return 0, caso a leitura tenha sido realizada com sucesso;
  * 1, caso contrário.
  */
int LerLinha(FILE *stream, char line[TAMANHO_LINHA]){
    if(fgets(line,TAMANHO_LINHA,stream)==NULL) return 1;
    line[strlen(line)-1] = '\0';
    return 0;
}

/**
 * @brief Função que libera o buffer
 */
void freeBuffer(){
   Linha* esse;
   Linha* prox;
   esse = Primeiro;
   while(esse!=NULL){
        prox = esse->ponteiro;
        free(esse->string);
        free(esse);
        esse = prox;
    }
}

/**
  * @brief Função que monta o grafo
  * @details monta grafo a partir dos dados lidos do arquivo de entrada
  * @return ponteiro grafo
  */
grafo* LerGrafo(){
      grafo* G;
      FILE* arquivo = AbrirArquivo();
      if(arquivo!=NULL){
        fillBuffer(arquivo);
        G = CriarGrafo();
        //BuscarVertices(arquivo,G);
        //LerVizinhos(G);
        //PrintaGrafo(G);
        //PrintaVertices(G);
        freeBuffer();
        FecharArquivo(arquivo);
      }
      return G;
}

/**
 * @brief Testa funções do grafo
 * @details Utilizada para testes das funções durante a implementação.
 */
void Teste3(){
    grafo* G = LerGrafo();
}
