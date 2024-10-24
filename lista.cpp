/* Alunos:  
    Marcelo Malcher Gillet de Loreto Melo
    Eduardo Fernandes Albuquerque 
*/

#include "lista.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/* Inicializa uma lista */
TipoLista *InicializaLista() {
  TipoLista *lista = (TipoLista *)malloc(sizeof(TipoLista));
  return lista;
}

/* Faz a lista ficar vazia */
void FLVazia(TipoLista *Lista) {
  Lista->Primeiro = 0;
  Lista->Ultimo = Lista->Primeiro;
}


/* Insere x após o último elemento da lista */
void Insere(Valor *x, TipoLista *Lista) {
  if (Lista->Ultimo >= 10000)
    cout << "Lista está cheia" << endl;
  else {
    Lista->valores[Lista->Ultimo] = *x;
    Lista->Ultimo++;
  }
}

/*Retorna o tamanho da lista */
int Tamanho_lista(TipoLista *Lista) {
  if (Lista == NULL)
    return -1;
  else
    return Lista->Ultimo;
}

/*Imprime os itens da lista na ordem de ocorrência */
void Imprime(TipoLista *Lista) {
  if (Tamanho_lista(Lista) == 0) {
    cout << "Lista vazia" << endl << endl;
  } else {
    cout << "Valores na lista" << endl;
    cout << "p - key" << endl;
    for (int Aux = Lista->Primeiro; Aux < Lista->Ultimo; Aux++) {
      cout << Aux << " - " << Lista->valores[Aux].valor << endl;
    }
    cout << endl;
  }
}

void BubleSort(TipoLista* lista){
    /*Instanciação das variáveis de troca, comparação e indexador(para controlar a maneira de percorrer a lista) */
    int indexador = 0;
    int comparacoes = 0;
    int trocas = 0;
    bool condi = true;        /*Variável da flag */
    /*Laço para continuar as trocas de valores caso ainda hajam trocas ou na ultima passagem teve trocas */
    while (condi){
        condi = false;
        /*Laço para percorrer a lista */
        for (int i = 0; i < Tamanho_lista(lista) - 1 - indexador; i++){
            comparacoes++;
            /* Condição para a troca dos valores (valor da posição i ser maior que a de i+1) */
            if (lista->valores[i].valor > lista->valores[i+1].valor){
                trocas++;
                int aux = lista->valores[i].valor;
                lista->valores[i].valor = lista->valores[i+1].valor;
                lista->valores[i+1].valor = aux;
                condi = true;
            }
        }
        indexador++;
    }
    cout << "Número de trocas: " << trocas << endl;
    cout << "Número de comparações: " << comparacoes << endl;
}

void QuickSort(TipoLista* lista, int esq, int dir, Valor* trocas, Valor* comp){
    /*Condição para ocorrer o algoritmo */
    if (esq < dir){
        /*Variavel para ter a posição do pivô */
        int posicao_particao = Particao(lista, esq, dir, trocas, comp);
        /*Divisão da sublista esquerda (com valores menores do que o pivô) */
        QuickSort(lista, esq, posicao_particao - 1, trocas, comp);
        /*Divisão da sublista direita (com valores maiores do que o pivõ) */
        QuickSort(lista, posicao_particao + 1, dir, trocas, comp);
    }
}

int Particao(TipoLista* lista, int esq, int dir, Valor* trocas, Valor* comp){
    /*Variáveis de controle que percorrerão a lista e o pivô */
    int i = esq;
    int j = dir - 1;
    int pivo = lista->valores[dir].valor;
    
    /*Laço com condição para continuar percorrendo a lista */
    while (i < j){
        /*Condição para i continuar percorrendo a lista e achar o valor de índice que será comparado */
        while ((i < dir) && (lista->valores[i].valor < pivo)){
            comp->valor++;
            i++;
        }
        /*Condição para j continuar percorrendo a lista e achar o valor de índice que será comparado */
        while ((j > esq) && (lista->valores[j].valor >= pivo)){
            comp->valor++;
            j--;
        }
        /*Condição para trocar valores que não sejam o pivô, mas que estejam fora de ordem na lista */
        if (i < j){
            comp->valor++;
            trocas->valor++;
            int aux = lista->valores[i].valor;
            lista->valores[i].valor = lista->valores[j].valor;
            lista->valores[j].valor = aux;
        }
    }
    /*Condição para ordenar o pivô */
    if(lista->valores[i].valor > pivo){
        comp->valor++;
        trocas->valor++;
        int aux = lista->valores[i].valor;
        lista->valores[i].valor = lista->valores[dir].valor;
        lista->valores[dir].valor = aux;
    }
    return i;
}

void CountingSort (TipoLista* lista, TipoLista* array, TipoLista* acumulativo, TipoLista* array_sorted, TipoLista* lista_sorted){
    int trocas = 0;
	int maximo = 0;
	for (int i = 0; i < Tamanho_lista(lista) ;i++){
		if (maximo < lista->valores[i].valor){
			maximo = lista->valores[i].valor;
		}/*Laço e condição para saber qual o maior valor da lista*/
	}
	
	for (int i = 0; i < maximo + 1 ;i++){
	    Valor *item = (Valor*) malloc(sizeof(Valor));
	    item->valor = i;
	    Valor *item2 = (Valor*) malloc(sizeof(Valor));
	    item2->valor = 0;
		Insere(item, array);
		Insere(item2, acumulativo);
	}/*Laço para fazer uma lista de 0 até o valor máximo e outra lista para fazer uma lista de 0's do tamanho do valor máximo*/
	
	for (int i = 0; i <Tamanho_lista(lista);i++){
		int indice = lista->valores[i].valor;
		acumulativo->valores[indice].valor += 1;
	}/*Laço para incrementar 1 na lista de 0's de acordo com a frequência de elementos na sequência desejada para ordenar */
	
	for (int i = 0; i <Tamanho_lista(acumulativo);i++){
		try{
			acumulativo->valores[i+1].valor = acumulativo->valores[i].valor + acumulativo->valores[i+1].valor;
		}
		catch(const runtime_error& e){
		}	
	}/*Laço para a fazer a soma do número atual mais a anterior e o resultado substitui a atual, isso na lista acumulativo*/
	/*o try e catch foi utilizado pois quando chegar no final da lista, dar erro por querer somar algo que não existe,
	com essa função, o erro é ignorado e segue o código*/
	
	for (int i = 0; i < Tamanho_lista(lista) ;i++){
	    Valor *item = (Valor*) malloc(sizeof(Valor));
	    item->valor = i+1;
	    Valor *item2 = (Valor*) malloc(sizeof(Valor));
	    item2->valor = 0;
		Insere(item, array_sorted);
		Insere(item2, lista_sorted);
	}/*Laço fazendo uma lista de 1 até o tamanho da lista principal e outra de 0's do tamanho da lista principal*/
	
	for (int i = 0; i < Tamanho_lista(lista) ;i++){
		int elemento = lista->valores[i].valor;
		lista_sorted->valores[acumulativo->valores[elemento].valor - 1].valor = lista_sorted->valores[acumulativo->valores[elemento].valor - 1].valor + lista->valores[i].valor;
		acumulativo->valores[elemento].valor = acumulativo->valores[elemento].valor - 1;
	}/*Laço pegando um elemento da lista principal, vendo o indice na lista acumulativo e pegando esse novo valor,
	esse valor será o novo indice na nova lista de 0's, onde será colocado o elemento pegado da lista principal,
	assim, ordenará a lista*/
	
	FLVazia(lista);
	for(int i = 0; i < Tamanho_lista(lista_sorted); i++){
	    trocas++;
	    Valor *item = (Valor*) malloc(sizeof(Valor));
        item -> valor = lista_sorted->valores[i].valor;
        Insere(item,lista);/*esvaziando a lista principal e inserindo a lista ordenada na lista vazia, para imprimir no final*/
	}
	cout << "Trocas: " << trocas << endl;
	cout << "Comparações: Este algoritmo não faz comparações diretamente" << endl;
}
