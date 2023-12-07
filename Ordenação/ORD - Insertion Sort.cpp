#include <iostream>
using namespace std;

//compara o que vai ser ordenado com o antes dele
void insertionSort(int vetor[], int tamanho) { //
    int i, chave, j;
    for (i = 1; i < tamanho; i++) {// i = posições do array ordenado
        chave = vetor[i]; 
        j = i - 1; // j = primeiro elemento não ordenado 
        while (j >= 0 && vetor[j] < chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1; // anda pra trás pra "conferir"
        }
        vetor[j + 1] = chave; //chave= vetor que tá sendo analisado
    }
}

int main() {
    int N, tam; // variáveis
    int i = 0; // contador
    int vetor[100]; // vetor

    cin >> N;

    while (N != 0) //parar de pedir valores quando digitar 0
    {
        vetor[i] = N;
        i++;
        cin >> N;
    }
    tam = i;

    insertionSort(vetor, tam); // chama a função

    for (i = 0; i < tam; i++) {
        cout << vetor[i] << " ";
    }

    return 0;
}
// Insertion sort = Tem a parte ordenada e não ordenada. Pega um por um