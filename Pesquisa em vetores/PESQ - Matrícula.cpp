#include <iostream>
#include <string>
using namespace std;

// struct dados dos alunos
struct Aluno {
    string nome;
    string curso;
    int matricula;
};

int main() {
    int n;
    cin >> n;

    //vetor alunos usando a struct aluno
    Aluno alunos[10000];

    // entrada de dados
    for (int i = 0; i < n; i++) {
        cin.ignore(); 
        getline(cin, alunos[i].nome); 
        getline(cin, alunos[i].curso);
		cin >> alunos[i].matricula; 
    }

    cin.ignore(); 
    string nomebuscado;
    getline(cin, nomebuscado);

    // procurar o aluno
    bool encontrado = false; // encontrado começa com o valor falso
    for (int i = 0; i < n; i++) {
        if (alunos[i].nome == nomebuscado) {
            encontrado = true; //caso o nome do aluno na posição i seja igual ao buscado encontrado se torna verdadeiro
            cout << alunos[i].nome << endl;
            cout << alunos[i].curso << endl;
            cout << alunos[i].matricula << endl;
            break;
        }
    }

    if (encontrado == false) {
        cout << "Aluno nao localizado" << endl;
    }

    return 0;
}
