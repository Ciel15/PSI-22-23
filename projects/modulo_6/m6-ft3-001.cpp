#include <iostream>
#include <string>
using namespace std;

struct Aluno
{
    string nome;
    Aluno *proximo;
    Aluno *anterior;

    Aluno(string nome) : nome(nome), proximo(nullptr), anterior(nullptr) {}
};

class ListaEncadeadaOrdenada
{
private:
    Aluno *primeiro;

public:
    ListaEncadeadaOrdenada() : primeiro(nullptr) {}

    void inserir(string nome)
    {
        Aluno *novo_aluno = new Aluno(nome);

        if (primeiro == nullptr)
        {
            // Caso a lista esteja vazia
            primeiro = novo_aluno;
        }
        else if (nome < primeiro->nome)
        {
            // Inserção no início da lista
            novo_aluno->proximo = primeiro;
            primeiro->anterior = novo_aluno;
            primeiro = novo_aluno;
        }
        else
        {
            // Inserção no meio ou no final da lista
            Aluno *atual = primeiro;

            while (atual->proximo != nullptr && atual->proximo->nome < nome)
            {
                atual = atual->proximo;
            }

            novo_aluno->proximo = atual->proximo;
            novo_aluno->anterior = atual;
            if (atual->proximo != nullptr)
            {
                atual->proximo->anterior = novo_aluno;
            }
            atual->proximo = novo_aluno;
        }
    }

    void remover(string nome)
    {
        if (primeiro == nullptr)
        {
            cout << "A lista está vazia." << endl;
            return;
        }

        Aluno *atual = primeiro;

        while (atual != nullptr && atual->nome != nome)
        {
            atual = atual->proximo;
        }

        if (atual == nullptr)
        {
            cout << "O aluno não foi encontrado na lista." << endl;
            return;
        }

        if (atual->anterior == nullptr)
        {
            // Remoção do primeiro elemento
            primeiro = atual->proximo;
            if (primeiro != nullptr)
            {
                primeiro->anterior = nullptr;
            }
        }
        else
        {
            atual->anterior->proximo = atual->proximo;
            if (atual->proximo != nullptr)
            {
                atual->proximo->anterior = atual->anterior;
            }
        }

        delete atual;
        cout << "Aluno removido com sucesso." << endl;
    }

    void mostrarComprimento()
    {
        int comprimento = 0;
        Aluno *atual = primeiro;

        while (atual != nullptr)
        {
            comprimento++;
            atual = atual->proximo;
        }

        cout << "Comprimento da lista: " << comprimento << endl;
    }

    void esvaziar()
    {
        Aluno *atual = primeiro;

        while (atual != nullptr)
        {
            Aluno *proximo = atual->proximo;
            delete atual;
            atual = proximo;
        }

        primeiro = nullptr;
        cout << "A lista foi esvaziada." << endl;
    }
};

int menu()
{
    int opc;
    
    cout << "[1] Inserir um novo registo de aluno                |\n";
    cout << "[2] Eliminar um registo contendo um determinado nome|\n";
    cout << "[3] Procurar por um registo com um dado nome        |\n";
    cout << "[4] Listar todos os registos                        |\n";
    cout << "
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    [0] Sair                                            |\n";
 
    cout << "Opcao: ";
    cin >> opc;
    return opc;
}

int main()
{

    int opcao;

    do          
        {
        system("cls");
        opcao = menu();
        switch (opcao)
        {
        case 1:
            ();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:;
            break;
        default:
            break;
        }

    } while (opcao != 0);

    ListaEncadeadaOrdenada lista;

    lista.inserir("Alice");
    lista.inserir("Carlos");
    lista.inserir("Eduardo");
    lista.inserir("Bianca");
    lista.inserir("Diana");

    lista.mostrarComprimento();
    lista.remover("Carlos");
    lista.mostrarComprimento();

    lista.esvaziar();
    lista.mostrarComprimento();

    return 0;
}
