#include <iostream>
#include <list>

using namespace std;

// função para ler uma lista de inteiros
void readList(list<int> &l)
{
    int n;
    cin >> n;

    // lê valores até encontrar um -1 e os adiciona no início da lista
    while (n != -1)
    {
        l.push_front(n);
        cin >> n;
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
    list<int> l1;
    list<int>::iterator it;

    int x;
    int y;

    readList(l1); // lê a lista de números

    cin >> x >> y; // lê dois números, x e y

    // percorre a lista
    for (it = l1.begin(); it != l1.end(); it++)
    {
        if (*it == x) // quando encontrar o número x
        {
            it++; // avança o iterador
            l1.insert(it, y); // insere o número y na posição seguinte
            break; // sai do loop
        }
    }

    // imprime a lista resultante
    for (it = l1.begin(); it != l1.end(); it++)
        cout << *it << " ";

    cleanList(l1); // limpa a lista antes de encerrar o programa

    return 0;
}
