/**
 * @file main.c
 * @author Fernanda Macedo de Sousa
 * @author Mariana Alencar do Vale
 * @brief Arquivo principal, o qual contém a execução do projeto 4
 * @details O arquivo a seguir contém a implementação de funções de iteração com o usuário, e execução de todas as
 * funções específicas do projeto de forma estruturada.
 * @see read.h
 * @see graph.h
 */
#include <stdio.h>
#include<stdlib.h>
#include "read.h"
#include "graph.h"

#ifdef _WIN32
	#define CLEAR "cls"
#else
	#define CLEAR "clear"
#endif

/**
 * @brief Cabeçalho do arquivo principal
 * @details Imprime informações das autoras do código.
 */
void Cabecalho (){
    system(CLEAR);
    system(CLEAR);
    printf("Aluna                    - Matricula\n");
    printf("Mariana Alencar do Vale  - 160014522\n");
    printf("Fernanda Macedo de Sousa - 170010058\n");
    printf("\n\n\n");
}

/**
 * @brief Opções do menu
 * @details Apresenta um menu de iteração com o usuário com as opções a serem realizadas.
 * @return escolha do usuário após ser lida.
 */
int Opcoes (){
		int escolha;
		printf("\n\n\n+TRABALHO GRAFOS 4+\n\n");
		printf("\n\n\n\nEscolha uma opcao:\n	1 - Ver grafo\n");
		printf("	2 - Ver comunidades detectadas\n");
		printf("	3 - Sair\n\n");
		printf("\n\nESCREVA O NUMERO DA OPCAO: ");
		scanf("%d",&esco3ha);
		return escolha;
}

/**
 * @brief Função recursiva do Menu do projeto
 * @details Função do loop de execução do projeto; nela são chamadas as funções implementadas de acordo
 * com a especificação do projeto 4 da disciplina TAG e apresentadas numa estrutura organizada.
 * @param Ponteiro para estrutura de grafo G (na execução da main() esse grafo será o lido do arquivo).
 */
void Menu (grafo* G){
		Cabecalho();
		int escolha = Opcoes();
		switch (escolha){
				case 1:
          Cabecalho();
					//funcao que printa grafo
					printf("\n\nAPERTE ENTER PARA CONTINUAR\n\n");
					getchar();
					getchar();
					Menu(G);
				break;

				case 2:
          Cabecalho();
					//funcao que mostra as comunidades
        			printf("\n\nAPERTE ENTER PARA CONTINUAR\n\n");
					getchar();
					getchar();
					Menu(G);
				break;

				case 3:
				Cabecalho();
				break;

				default: Menu(G);
		}

}

/**
 * @brief Função principal
 * @details Função que roda o programa, nela são chamadas a função que cria o grafo a partir do arquivo lido LerGrafo() e
 * a função do menu do programa, Menu(). Após a execução do projeto o grafo é liberado através da função LiberaGrafo().
 */
int main(){
	Cabecalho();
	 grafo* G = LerGrafo();
	 Menu(G);
	 if(G!=NULL){
	 			FreeGraph(G);
	 }
	 getchar();
	 getchar();
    return 0;
}
