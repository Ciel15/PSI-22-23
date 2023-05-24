#include <iostream>
#include <string>
using namespace std;
struct aluno
{
    float nota;
    string nome;
};
struct registo
{
    aluno al;
    registo *next;
};
registo *inicio = NULL;
void rgtr()
{
    system("cls");

    registo *p;

    p = new registo;

    cout << "Nome : ";
    cin.ignore();
    getline(cin, p->al.nome);
    do
    {
        cout << "\nNota :";
        cin >> p->al.nota;
    } while (p->al.nota < 0 || p->al.nota > 20);
    if (inicio == NULL)
        p->next = NULL;
    else
        p->next = inicio;
    inicio = p;

    system("pause");
}
int eliminar_registo()
{
    registo *aux, *to_delete = NULL;
    string nome;
    system("cls");
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);
    aux = inicio;
    // int i = 1, j = 1;
    do
    {
        if (aux->al.nome == nome)
        {
            // delete
            to_delete = aux;
            break;
        }

        aux = aux->next;
        // i++;
    } while (aux != NULL);

    if (to_delete != NULL)
    {

        aux = inicio;
        do
        {
            if (aux->next == to_delete)
            {
                aux->next = to_delete->next;
                delete to_delete;
                return 1;
            }

            aux = aux->next;
        } while (aux != NULL);
    }
    return 0;
}
int Procurar_Registo()
{
    
    registo *aux;
    string nome;
    system("cls");
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);
    aux = inicio;
    do
    {
        if (aux->al.nome == nome)
        {
            cout << "Nome - " << aux->al.nome << "\n\n";
            cout << "Nota - " << aux->al.nota << "\n\n";
            return 1;
           
        }

        aux = aux->next;
       
    } while (aux != NULL);

    return 0; 
}
void Listar_Registos()
{
    system("cls");
    registo *aux;

    aux = inicio;
    int i = 1;
    while (aux != NULL)
    {

        cout << aux->al.nome << " - " << aux->al.nota << "\n\n";
        aux = aux->next;
        i++;
    }
    system("pause");
}

int menu()
{
    int opc;
    cout << "******************************************************\n";
    cout << "|[1] Inserir um novo registo de aluno                |\n";
    cout << "|[2] Eliminar um registo contendo um determinado nome|\n";
    cout << "|[3] Procurar por um registo com um dado nome        |\n";
    cout << "|[4] Listar todos os registos                        |\n";
    cout << "|[0] Sair                                            |\n";
    cout << "******************************************************\n";
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
            rgtr();
            break;
        case 2:

            if (eliminar_registo() == 1)
            {
                cout << "Registo eliminado\n\n";
            }
            else
                cout << "O Registo nao foi eliminado\n\n";
            break;
        case 3:
            if(Procurar_Registo() == 0)
            {
                cout << "Nome nao encontrado\n\n";
            };
            system ("pause");
            break;
        case 4:
            Listar_Registos();
            break;
        default:
            break;
        }

    } while (opcao != 0);

    return 0;
}