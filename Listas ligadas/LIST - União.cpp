#include <iostream>
#include <list>

using namespace std;

// função para ler uma lista de inteiros
void readList(list<int> &l)
{
    int n;
    cin >> n;

    // le valores ate encontrar 0 e adiciona lista
    while (n != 0)
    {
        l.push_back(n);//no final
        cin >> n;
    }
}

// função para ordenar duas listas em ordem ascendente e armazenar o resultado em uma terceira lista
void sortListASC(list<int> &l1, list<int> &l2, list<int> &l3)
{
    list<int>::iterator it1 = l1.begin();
    list<int>::iterator it2 = l2.begin();

    // combina as listas ordenadas de forma menor para o maior
    while (it1 != l1.end() && it2 != l2.end())
    {
        if (*it1 < *it2)
        {
            l3.push_back(*it1);
            it1++;
        }
        else if (*it1 > *it2)
        {
            l3.push_back(*it2);
            it2++;
        }
        else
        {
            l3.push_back(*it1);
            it1++;
            it2++;
        }
    }

    // adiciona o restante dos elementos de l1, se houver
    while (it1 != l1.end())
    {
        l3.push_back(*it1);
        it1++;
    }

    // adiciona o restante dos elementos de l2, se houver
    while (it2 != l2.end())
    {
        l3.push_back(*it2);
        it2++;
    }
}

// função para limpar uma lista
void cleanList(list<int> &l)
{
    while (!l.empty())
        l.pop_front();
}

int main()
{
    list<int> l1, l2, l3;

    // leitura das duas listas
    readList(l1);
    readList(l2);

    // ordena as listas em ordem menor para o maior e armazena o resultado em l3
    sortListASC(l1, l2, l3);

    // imprime a lista resultante
    for (list<int>::iterator i = l3.begin(); i != l3.end(); i++)
    {
        cout << *i << " ";
    }

    // limpa as listas antes de encerrar o programa
    cleanList(l1);
    cleanList(l2);
    cleanList(l3);

    return 0;
}
