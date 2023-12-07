#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> fila; //declara a fila
    list<int>::iterator it; // declara o iterator

//ler valores
    for (int i = 0; i < 4; i++)
    {
        int num;
        cin >> num;
        fila.push_back(num); //inserir os elementos no final da fila
    }

    it = fila.begin(); //it está apontando para o inicio da fila
    while (!fila.empty())  //empty = vazia (então fila não vazia)
    {
        cout << *it << endl; //imprime it (inicio)
        it = fila.erase(it); // fila.erase(it) apaga oq o it está apontando
        // então apaga o primeiro e outro vira o primeiro então vai "varrendo" o vetor
    }

    return 0;
}