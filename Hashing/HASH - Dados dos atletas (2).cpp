#include <iostream>
#include <iomanip> // Para std::fixed e std::setprecision
#include <cstring>

using namespace std;

struct info
{
    char nome[100];
    int idade;
    float peso;
    float altura;
};

struct dado
{
    info atleta; // nome, idade, peso e altura de cada atleta
    int k;       // chave
    int status;  // 0:vazio, 1:ocupado, 2:removido
};

int hash1(char *nome, int m)
{
    int soma = 0;
    for (int i = 0; nome[i] != '\0'; i++)
    {
        soma += nome[i];
    }
    return soma % m;
}

int hash2(char *nome, int m)
{
    return 1 + (hash1(nome, m - 1));
}

int double_hash(char *nome, int m, int i)
{
    return (hash1(nome, m) + i * hash2(nome, m)) % m;
}

int hash_insert(dado T[], int m, char *nome, int idade, float peso, float altura)
{
    int i = 0;
    int j;
    do
    {
        j = double_hash(nome, m, i);
        if (T[j].status == 0 || T[j].status == 2)
        {
            strcpy(T[j].atleta.nome, nome);
            T[j].atleta.idade = idade;
            T[j].atleta.peso = peso;
            T[j].atleta.altura = altura;
            T[j].status = 1;
            return j;
        }
        else if (strcmp(T[j].atleta.nome, nome) == 0 && T[j].status == 1)
        {
            return j; // Atleta jÃ¡ existe na tabela
        }
        else
        {
            i = i + 1;
        }
    } while (i != m);

    return -1; // Tabela cheia
}

void mostrar_atleta(info atleta)
{
    cout << "Nome: " << atleta.nome << endl;
    cout << "Idade: " << atleta.idade << endl;
    cout << "Peso: " << fixed << setprecision(1) << atleta.peso << endl; // Fixando 1 casa decimal para o peso
    cout << fixed << setprecision(2) << "Altura: " << atleta.altura << endl; // Fixando 2 casas decimais para a altura
}

void mostrar_tabela(dado t[], int m)
{
    for (int i = 0; i < m; ++i)
    {
        if (t[i].status == 1)
        {
            mostrar_atleta(t[i].atleta);
            cout << endl;
        }
        else if (t[i].status == 0)
        {
            // NÃ£o faz nada, nÃ£o imprime nada para posiÃ§Ãµes vazias
        }
        else if (t[i].status == 2)
        {
            // NÃ£o faz nada, nÃ£o imprime nada para posiÃ§Ãµes removidas
        }
    }
}

int hash_search(dado t[], int m, char *nome)
{
    int i = 0;
    int j;
    do
    {
        j = double_hash(nome, m, i);
        if (strcmp(t[j].atleta.nome, nome) == 0 && t[j].status == 1)
        {
            return j;
        }
        i = i + 1;
    } while (t[j].status != 0 && i < m);

    return -1;
}

int hash_remove(dado t[], int m, char *nome)
{
    int j;
    int i = 0;
    int index = -1; // Adicionando a inicializaÃ§Ã£o de index
    do
    {
        j = double_hash(nome, m, i);
        if (strcmp(t[j].atleta.nome, nome) == 0 && t[j].status == 1)
        {
            t[j].status = 2; // Marcando como removido
            index = j;       // Atribuindo o valor de j para index
            return 0;        // conseguiu remover
        }
        i = i + 1;
    } while (t[j].status != 0 && i < m);

    return -1; // Atleta nÃ£o estÃ¡ na tabela
}

int main()
{
    int m;
    cin >> m;
    dado T[m];

    for (int i = 0; i < m; ++i)
    {
        T[i].status = 0;
    }

    int opc;
    char nome[100];
    int idade;
    float peso, altura;
    int index;

    do
    {
        cin >> opc;

        switch (opc)
        {
        case 1: // Inserir
            cin.ignore(); // Para limpar o buffer do teclado antes de ler a string
            cin.getline(nome, 100);
            cin >> idade >> peso >> altura;
            hash_insert(T, m, nome, idade, peso, altura);
            break;
        case 2: // Pesquisar
            cin.ignore(); // Para limpar o buffer do teclado antes de ler a string
            cin.getline(nome, 100);
            index = hash_search(T, m, nome);
            if (index != -1)
            {
                mostrar_atleta(T[index].atleta);
            }
            else
            {
            	cout<<endl;
                cout << nome << " nao encontrado" << endl;
                cout<<endl;
            }
            break;
        case 3: // Remover
            cin.ignore(); // Para limpar o buffer do teclado antes de ler a string
            cin.getline(nome, 100);
            hash_remove(T, m, nome);
            break;
        case 4: // Listar
            mostrar_tabela(T, m);
            break;
        }

    } while (opc != 5);

    return 0;
}
