#include <iostream>
#include <list>

using namespace std;

// função para encontrar um elemento na lista
bool encontrar(list<int> lista, int x)
{
    // declarou o iterator e deu o valor(aponta) dele como inicio da lista, enquanto it não for o end vai varrer a lista
    for (list<int>::iterator it = lista.begin(); it != lista.end(); it++)
    {
        
        if (*it == x)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    list<int> fila;         // declaração de uma lista de inteiros
    list<int>::iterator x;  // iterador para percorrer a lista
    int find;               // valor a ser procurado na lista

    int flag = 1;
    while (flag)
    {
        int n;
        cin >> n;

        // se o valor lido for 0, encerra o loop
        if (n == 0)
        {
            flag = 0;
        }
        else
        {
            // adiciona o valor lido na lista
            fila.push_back(n);
        }
    }

    cin >> find; // le o valor procurado

    // chama a função encontrar para verificar se o valor está na lista
    if (encontrar(fila, find))
    {
        cout << "Encontrado" << endl;
    }
    else
    {
        cout << "Nao encontrado" << endl;
    }

    // Limpa a lista
    while (!fila.empty())
        fila.pop_front();

    return 0;
}
