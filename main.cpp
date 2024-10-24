/* Alunos:  
    Marcelo Malcher Gillet de Loreto Melo
    Eduardo Fernandes Albuquerque 
*/

#include "lista.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <random>
#include <chrono>

using namespace std;

int main()
{
    /* Inicio do temporizador */
    auto start = std::chrono::high_resolution_clock::now();
    
    /* Instanciação da lista */
    TipoLista* lista = InicializaLista();
    FLVazia(lista);
    
    /* Escolha do numero de valores */
    char escolhaUm;
    cout << "Escolha quantos valores você deseja que a lista tenha:" << endl;
    cout << "a - 10" << endl;
    cout << "b - 100" << endl;
    cout << "c - 1000" << endl;
    cout << "d - 10000" << endl;
    cin >> escolhaUm;
    
    /* Variáveis para a quantidade de valores escolhida e range de números que podem ser randomicos */
    int valoresNum = 0;
    int valorRand = 0;
    
    /* Laço para não aceitar valores fora da a/b/c/d */
    while(escolhaUm != 'a' && escolhaUm != 'b' && escolhaUm != 'c' && escolhaUm != 'd'){
        cout << " " << endl;
        cout << "Ops! Foi digitado um valor que não é válido, por favor, digite novamente (a/b/c/d): " << endl;
        cin >> escolhaUm;
    }
    
    /* Condições que determinam as quantidades de valores na lista */
    if(escolhaUm == 'a'){
        valoresNum = 10;
        valorRand = 5;
    }
    else if(escolhaUm == 'b'){
        valoresNum = 100;
        valorRand = 50;
    }
    else if(escolhaUm == 'c'){
        valoresNum = 1000;
        valorRand = 500;
    }
    else if(escolhaUm == 'd'){
        valoresNum = 10000;
        valorRand = 5000;
    }
    
    /* Instanciação dos números randomicos */
    random_device rd;
    uniform_int_distribution<int> dist(0, valoresNum + valorRand);
    
    /* Escolha da ordem inicial da lista */
    char escolhaDois;
    cout << " " << endl;
    cout << "Agora, escolha se voce deseja que a lista esteja ordenada de forma:" << endl;
    cout << "a - Crescente" << endl;
    cout << "b - Decrescente" << endl;
    cout << "c - Aleatória" << endl;
    cin >> escolhaDois;
    
    /* Laço para não aceitar valores fora da a/b/c */
    while(escolhaDois != 'a' && escolhaDois != 'b' && escolhaDois != 'c'){
        cout << " " << endl;
        cout << "Ops! Foi digitado um valor que não é válido, por favor, digite novamente (a/b/c): " << endl;
        cin >> escolhaDois;
    }
    
    /* Escolha de ou Crescente ou Aleatória */
    if(escolhaDois != 'b'){
        /* Laço para colocar os valores na lista */
        for (int i = 1; i <= valoresNum; i++){
            /* Ordenação Crescente */
            if(escolhaDois == 'a'){
                Valor* item;
                item = (Valor*) malloc(sizeof(Valor));
                item->valor = i;
                Insere(item, lista);
            }
            /* Ordenação Aleatória */
            else{
                Valor* item;
                item = (Valor*) malloc(sizeof(Valor));
                item->valor = dist(rd);
                Insere(item, lista);
            }
        }
    }
    /* Escolha Decrescente */
    else{
        /* Ordenação Decrescente */
        for (int i = valoresNum; i > 0; i--){
            Valor* item;
            item = (Valor*) malloc(sizeof(Valor));
            item->valor = i;
            Insere(item, lista);
        }
    }
    
    /* Escolha de mostrar ou não a lista original */
    char escolhaTres;
    cout << " " << endl;
    cout << "Antes de escolher o algoritmo, deseja ver a lista original? (s/n)" << endl;
    cin >> escolhaTres;
    
    if(escolhaTres == 's'){
        Imprime(lista);
    }
    
    /* Escolha de qual tipo de algoritmo usar */
    char escolhaQuatro;
    cout << " " << endl;
    cout << "Agora, escolha qual algoritmo de ordenação você deseja:" << endl;
    cout << "1 - BubleSort" << endl;
    cout << "2 - QuickSort" << endl;
    cout << "3 - CountingSort" << endl;
    cin >> escolhaQuatro;
    cout << " " << endl;
    
    /* Laço para não aceitar valores fora de 1/2/3 */
    while(escolhaQuatro != '1' && escolhaQuatro != '2' && escolhaQuatro != '3'){
        cout << " " << endl;
        cout << "Ops! Foi digitado um valor que não é válido, por favor, digite novamente (1/2/3): " << endl;
        cin >> escolhaQuatro;
    }

    cout << " " << endl;
    /* Escolha BubleSort */
    if (escolhaQuatro == '1'){
        BubleSort(lista);
        Imprime(lista);
    }
    /* Escolha QuickSort */
    else if (escolhaQuatro == '2'){
        /* Instanciação de ponteiros para guardar as comparações e trocas */
        Valor* trocas;
        trocas = (Valor*) malloc(sizeof(Valor));
        trocas->valor = 0;
        Valor* comp;
        comp = (Valor*) malloc(sizeof(Valor));
        comp->valor = 0;
        QuickSort(lista, 0, valoresNum - 1, trocas, comp);
        cout << "trocas: " << trocas->valor << endl;
        cout << "comparações: " << comp->valor << endl;
        Imprime(lista);
    }
    /* Escolha CountingSort */
    else if (escolhaQuatro == '3'){
        /* Instanciação da lista que vai até o valor máximo da lista original */
        TipoLista* array = InicializaLista();
        FLVazia(array);
        /* Instanciação da lista que possui a frequência dos valores da lista original */
        TipoLista* acumu = InicializaLista();
        FLVazia(acumu);
        /* Instanciação da lista que vai de 1 até o tamanho da lista acumu */
        TipoLista* array_sorted = InicializaLista();
        FLVazia(array_sorted);
        /* Instanciação da lista ordenada */
        TipoLista* lista_sorted = InicializaLista();
        FLVazia(lista_sorted);
        CountingSort(lista, array, acumu, array_sorted, lista_sorted);
        Imprime(lista);
    }
    /* Fim do temporizador */
    auto end = std::chrono::high_resolution_clock::now();
    /* Tempo do temporizador */
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << "Tempo de execução: " << duration.count() << " ms" << endl;

    return 0;
}
