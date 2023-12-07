#include <iostream>
#include <iomanip>

using namespace std;

void bubbleSort(int vetor[], int tam) {
    int i, j; // contadores
    int k = 0; // contador do true
    int trab;
    bool troca; // muda o estado para V ou F
    int limite; // guarda a ultima posição do vetor que terá verificação

    troca = true;
    limite = tam - 1; // vetor começa na posição 0

    while (troca) { // = verdadeiro, funciona como se fosse um for que faz recomeçar
        troca = false;

        for (i = 0; i < limite; i++) { // faz a varredura do array/ leitura par a par
            if (vetor[i] > vetor[i + 1]) // se posição anterior for maior que posterior, troca
            {                         // o if verifica se precisa trocar ou não
                trab = vetor[i]; // variavel que está sendo trabalhada

                cout << "New trab:" << trab << endl;
                // estrutura básica bubble sort
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = trab;
                j = i;

                troca = true;
                k++; // contador da troca
            }
        }
        limite = j;
    }
    cout << "Contador:" << k << endl;
}

int main() {
    int N; // variaveis
    int i = 0; // contador
    int vetor[100]; // vetor

    // Entra com N valores inteiros em um vetor
    cin >> N;

    for (i = 0; i < N; i++) {
        cin >> vetor[i];
    }

    bubbleSort(vetor, N); // chama a função

    return 0;
}

// bubble sort = O maior elemento após a primeira analise fica no lugar certo
// O IF QUE DEFINE SE VAI SER CRESCENTE OU DECRESCENTE oq tem de errado??
