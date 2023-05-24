#include <iostream>
using namespace std;

struct Node {
    int dados;  // campos de dados
    Node *px;   // apontador para o próximo nó
};

int main() {
    Node *inicio; // apontador para início da lista
    Node *p;      // variável auxiliar
    Node *seg;
    Node *aux;

    inicio = NULL;  // lista vazia
    p = new Node;   // criar 1º elemento da lista
    // atualizar ponteiros
    inicio = p;
    p->px = NULL;
    // preencher 1º elemento da lista com dados
    p->dados = 10;

    cout << p->dados << endl;
    cout << "Valor de p: " << p << endl;
    cout << "Valor de inicio: " << inicio << endl;
    cout << "Valor de px (1 no): " << p->px << endl;

    // inserir segundo elemento
    p = new Node;
    seg = p;
    inicio->px = p;
    p->dados = 20;
    p->px = NULL;

    // inserir terceiro elemento
    p = new Node;
    seg->px = p;
    seg = p;
    p->dados = 30;
    p->px = NULL;

    // imprimir valores da lista
    aux = inicio;
    int i = 1;
    do
    {
        printf("Elementos %d: %d\n", i, aux->dados);
        aux = aux->px;
        i++;
    } while (aux != NULL);
  
    return 0;
}