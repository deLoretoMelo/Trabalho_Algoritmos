/* Alunos:  
    Marcelo Malcher Gillet de Loreto Melo
    Eduardo Fernandes Albuquerque 
*/

#include <iostream>
#include <string>

using namespace std;

/* Struct dos valores da lista */
typedef struct {
    int valor;
} Valor;

/* Struct da lista */
typedef struct{
    Valor valores[10000];
    int Primeiro, Ultimo;
} TipoLista;

/* Instanciação das funções da lista e de ordenação */
TipoLista *InicializaLista();
void FLVazia(TipoLista *);
int Tamanho_lista(TipoLista *);
void Insere(Valor *, TipoLista *);
void Imprime(TipoLista *);
void BubleSort(TipoLista*);
void QuickSort(TipoLista*, int, int, Valor*, Valor*);
void CountingSort(TipoLista*, TipoLista*, TipoLista*, TipoLista*, TipoLista*);
int Particao(TipoLista*, int, int, Valor*, Valor*);
