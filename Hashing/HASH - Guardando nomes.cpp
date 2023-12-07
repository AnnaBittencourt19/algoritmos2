#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

struct dado
{
    char info[50]; // Informação
    int k;         // Chave
    int status;    // 0: vazio, 1: ocupado, 2: removido
};

// Função de hash principal
int h1(int k, int m)
{
    int res;
    res = k % m;
    if (res < 0)
        res += m;
    return res;
}

// Função de hash secundária
int h2(int k, int m)
{
    return 1 + (k % (m - 1));
}

// Função de double hashing
int dhash(int k, int i, int m)
{
    int res;
    res = h1(k, m) + i * h2(k, m) % m;
    if (res < 0)
        res += m;
    if (res >= m)
        res -= m;
    return res;
}

// Função para calcular a chave com base na soma dos valores ASCII dos caracteres
int calcularChave(const char *info)
{
    int k = 0;
    for (int i = 0; i < strlen(info); i++)
        k += (int)info[i];
    return k;
}

// Inserção na tabela hash
int hash_insert(dado t[], int m, const char *info)
{
    int i = 0;
    int j = 0;
    int k = calcularChave(info);

    do
    {
        j = dhash(k, i, m);
        if (t[j].status != 1)
        {
            t[j].k = k;
            t[j].status = 1;
            strcpy(t[j].info, info); // Armazena a informação na tabela
            return j;                 // Retorna a posição onde o elemento foi inserido
        }
        else
            i++;
    } while (i != m);
    return -1; // Retorna -1 se a tabela estiver cheia
}

// Procura na tabela hash
int hash_search(dado t[], int m, const char *info)
{
    int i = 0;
    int j = 0;
    int k = calcularChave(info);

    do
    {
        j = dhash(k, i, m);
        if (t[j].status == 0)
            return -1; // A posição está vazia, então a informação não está na tabela
        else if (t[j].status == 1 && t[j].k == k)
            return j; // A informação foi encontrada na posição j
        else
            i++;

    } while (i != m);

    return -1; // A informação não está na tabela
}

// Remoção na tabela hash
int hash_remove(dado t[], int m, const char *info)
{
    int j;
    int k = calcularChave(info);
    j = hash_search(t, m, info);

    if (j != -1)
    {
        t[j].status = 2; // Marcado como removido
        t[j].k = -1;     // Zera a chave
        return 0;        // Conseguiu remover
    }
    else
        return -1; // A informação não está na tabela
}

// Listar a tabela hash
void listar_tabela(dado t[], int m)
{
    for (int i = 0; i < m; i++)
    {
        if (t[i].status == 1)
            cout << t[i].info << endl;
        else if (t[i].status == 2)
            cout << "Vazio" << endl;
        else
            cout << "Vazio" << endl;
    }
}

int main()
{
    int i, j;
    int m;           // Tamanho da tabela
    int pos;
    dado t[50];       // Tabela hash
    int op;           // Opções do switch
    char info[50];

    cin >> m; // Lê o tamanho da tabela

    // Inicializa a tabela hash
    for (i = 0; i < m; i++)
    {
        t[i].status = 0;
    }

    do
    {
        cin >> op; // Lê a operação desejada

        switch (op)
        {
        case 1:
            cin >> info;

            pos = hash_insert(t, m, info); // Insere a informação na tabela e armazena a posição
            break;

        case 2:
            cin >> info;

            pos = hash_search(t, m, info);
            if (pos == -1)
                cout << info << " nao encontrado" << endl;
            else
                cout << info << " encontrado na posicao " << pos << endl;

            break;

        case 3:
            cin >> info;

            if (hash_remove(t, m, info) == -1)
                cout << info << " nao encontrado" << endl;

            break;

        case 4:
            listar_tabela(t, m);
            break;
        }

    } while (op != 5);

    return 0;
}
