#include <iostream>
#include <vector>
#include <algorithm>

struct Aluno
{
    string nome;
    int nota;
};

vector<Aluno> baseDados;

void inserirRegistro()
{
    Aluno novoAluno;
    cout << "Nome do aluno: ";
    cin >> novoAluno.nome;
    cout << "Nota do aluno: ";
    cin >> novoAluno.nota;
    baseDados.push_back(novoAluno);
    cout << "Registro inserido com sucesso!" << endl;
}

void eliminarRegistro()
{
    string nome;
    cout << "Nome do aluno a ser eliminado: ";
    cin >> nome;
    auto it = find_if(baseDados.begin(), baseDados.end(), [nome](const Aluno &aluno)
                      { return aluno.nome == nome; });
    if (it != baseDados.end())
    {
        baseDados.erase(it);
        cout << "Registro eliminado com sucesso!" << endl;
    }
    else
    {
        cout << "Registro não encontrado." << endl;
    }
}

void procurarRegistro()
{
    string nome;
    cout << "Nome do aluno a ser procurado: ";
    cin >> nome;
    auto it = find_if(baseDados.begin(), baseDados.end(), [nome](const Aluno &aluno)
                      { return aluno.nome == nome; });
    if (it != baseDados.end())
    {
        cout << "Nome: " << it->nome << ", Nota: " << it->nota << endl;
    }
    else
    {
        cout << "Registro não encontrado." << endl;
    }
}

void listarRegistros()
{
    cout << "Lista de registros:" << endl;
    for (const auto &aluno : baseDados)
    {
        cout << "Nome: " << aluno.nome << ", Nota: " << aluno.nota << endl;
    }
}

int main()
{
    int opcao = -1;
    while (opcao != 0)
    {
        cout << "Menu de Operações:" << endl;
        cout << "1. Inserir novo registro" << endl;
        cout << "2. Eliminar registro" << endl;
        cout << "3. Procurar registro" << endl;
        cout << "4. Listar todos os registros" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            inserirRegistro();
            break;
        case 2:
            eliminarRegistro();
            break;
        case 3:
            procurarRegistro();
            break;
        case 4:
            listarRegistros();
            break;
        case 0:
            cout << "Encerrando o programa..." << endl;
            break;
        default:
            cout << "Opção inválida." << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}
