/**
 * @file graph.h
 * @author Fernanda Macedo de Sousa
 * @author Mariana Alencar do Vale
 * @brief Biblioteca de implementação do grafo
 * @detais A biblioteca graph.h contém o arquivo com a descrição das funções
 * utilizadas para a implementação do grafo.
 * @see graph.c
 */

 #ifndef GrafoBibliotecacodigosprojeto4tag
 #define GrafoBibliotecacodigosprojeto4tag



/**
  * @brief Inicializa Grafo
  * @details Aloca memoria para a estrutura do grafo
  * @return ponteiro para a estrutura grafo criada.
  */
grafo* CriarGrafo();


/**
  * @brief free grafo
  * @details libera o grafo e seus elementos
  * @param ponteiro para grafo
  */
void FreeGraph(grafo* G);

/**
 * @brief Testa funções do grafo
 * @details Utilizada para testes das funções durante a implementação.
 */
void Teste1();

#endif
