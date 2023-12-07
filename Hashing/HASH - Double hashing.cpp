#include <iostream>
#include <cmath>

using namespace std;

int h1(int k, int m) //primeira função auxiliar 
{
    int h;

    // k mod m
    h = k % m;

    if (h < 0)
    {
        h += m;
    }

    return h;
}

int h2(int k, int m) // segunda função auxiliar 
{
    int h;

    h = 1 + (k % (m - 1)); //o resultado será o valor que a função vai imprimir

    if (h < 0)
    {
        h += m;
    }

    return h; //retorna o valor de h então ao chamar h2(k,m) está chamando o valor de h 
}

// double hashing ("união" dos dois hash auxiliares 
int dhash(int k, int m, int i)
{
    int h;

    h = (h1(k, m) + (i * h2(k, m))) % m; //formula (padrão)

    return h;
}

int main()
{
    int m; // tamanho da tabela
    int k; // chave a ser inserida na tabela
    int i;

    cin >> k >> m;

//for para imprimir os valores
    for (i = 0; i < m; i++)
    {
        cout << dhash(k, m, i) << " ";
    }

    cout << endl;

    return 0;
}