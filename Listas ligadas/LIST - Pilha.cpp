#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> pilha;

//ler elementos
    for (int i = 0; i < 4; i++)
    {
        int num;
        cin >> num;
        pilha.push_front(num);
    }

//enquanto a pilha não estiver vázia
    while (!pilha.empty())
    {
        cout << pilha.front() << endl; //imprimir o primeiro
        pilha.pop_front(); //remove o primeiro da lista, então vai andando entre os outros elementos
    }

    return 0;
}