/*
	Esses sitema tem o objetivo de registar dados de alunos em uma tabela hash.
	O processo de cadastro de alunos � o seguinte:
		1 - Primeiro os dados do aluno s�o informados pelo usu�rio;
		2 - Em seguida, o aluno entra na fila de matr�culas;
		3 - Assim que a fila � processada, os alunos s�o registrados na tabela.
		Obs.: A tabela tem um limite de matr�culas e os demais alunos que n�o puderem ser registrados devem permanecer na fila.
	O processo de exclus�o de alunos � o seguinte:
		1 - O aluno � buscado na tabela e iserido em uma pilha de an�lises;
		2 - Quando o cosnelho analisa a pilha, os alunos s�o exclu�dos da tabela.
		Obs.: O conselho s� processa 5 alunos da pilha por vez.
	Os usu�rios podem ainda gerar listas de alunos ativos por curso e buscar os dados de um aluno pela matr�cula. 

*/


#include<iostream>
#include<list>
#include <locale.h> 
#define MAX_CURSOS 7
#define MAX_PROCESSOS_CONSELHO 5
using namespace std;
const string SIGLAS_CURSOS[MAX_CURSOS] = {"GEC", "GES", "GEB", "GET", "GEE", "GEP", "GEA"};

struct Aluno{
	int matricula;
	string nome;
	int curso;
	int status;
};

int hash_aux(int k,int m){
	return k % m;	
}

int hash_aux2(int k,int m){
	return 1+(k % (m-1));
}

int hash_duplo(int k,int m, int i){
	return (hash_aux(k,m)+i*hash_aux2(k,m))%m;	
}

int insere_aluno(Aluno tabela_hash[], int m, Aluno aluno){
	int pos, i = 0;
	while(i<m){
		pos = hash_duplo(aluno.matricula, m, i);
		if(tabela_hash[pos].status != 1){
			tabela_hash[pos] = aluno;
			tabela_hash[pos].status = 1;
			return pos;
		}
		i++;
	}
	return -1;	
}

void lista_cursos(){
	cout<<"Cursos dispon�veis: "<<0<<": "<<SIGLAS_CURSOS[0];
	for(int i=1;i<MAX_CURSOS;i++){
		cout<<", "<<i<<": "<<SIGLAS_CURSOS[i];
	}
	cout<<endl;
}

int solicita_curso(){
	int curso;
	lista_cursos();
	while(true){
		cout<<"Digite o curso (0 a "<<MAX_CURSOS-1<<"): ";
		cin>>curso;
		if(curso < 0 || curso >= MAX_CURSOS)
			cout<<"Curso inv�lido."<<endl;
		else
			return curso;
	}
	return -1;
}

Aluno novo_aluno(){
	Aluno novo;
	cout<<"Digite a matr�cula do aluno: ";
	cin>>novo.matricula;
	cin.ignore();
	cout<<"Digite o nome do aluno: ";
	getline(cin,novo.nome);
	
	novo.curso = solicita_curso();
	return novo;
}

void exibe_aluno(Aluno a){
	cout<<endl<<"Informa��es do aluno "<<a.nome<<endl;
	cout<<"Matr�cula: "<<a.matricula<<endl;
	cout<<"Curso: "<<SIGLAS_CURSOS[a.curso]<<endl<<endl;	
}

void lista_alunos(Aluno tabela_hash[], int m){
	for(int i=0;i<m;i++){
		cout<<"Posi��o "<<i<<": ";
		if(tabela_hash[i].status == 1)
			exibe_aluno(tabela_hash[i]);
		else if(tabela_hash[i].status == 2)
			cout<<"Aluno removido.";
		else
			cout<<"Matr�cula dispon�vel.";
		cout<<endl;
	}
}

void lista_alunos_curso(Aluno tabela_hash[], int m, int curso){
	int contador = 0;
	for(int i=0;i<m;i++){
		if(tabela_hash[i].curso == curso){
			if(tabela_hash[i].status == 1){
				exibe_aluno(tabela_hash[i]);
				contador++;
			}
		}
	}
	if(contador == 0)
		cout<<"Nenhum aluno matriculado nesse curso."<<endl;
}

int remover_aluno(Aluno tabela_hash[], int m, int matricula){
	int pos, i = 0, status = 1;
	while(i<m){
		pos = hash_duplo(matricula, m, i);
		status = tabela_hash[pos].status;
		if(status == 0)
			return -1;
		if(status == 1 && tabela_hash[pos].matricula == matricula){
			tabela_hash[pos].matricula = -1;
			tabela_hash[pos].status = 2;
			return pos;
		}
		i++;
	}
	return -1;		
}

int buscar_aluno(Aluno tabela_hash[], int m, int matricula){
	int pos, i = 0, status = 1;
	while(i<m){
		pos = hash_duplo(matricula, m, i);
		status = tabela_hash[pos].status;
		if(status == 0)
			return -1;
		if(status == 1 && tabela_hash[pos].matricula == matricula){
			return pos;
		}
		i++;
	}
	return -1;		
}

int menu(){
	int op;
	cout<<"\t\t\tMenu\n";
	cout<<"\t1:\tInserir aluno na fila de matr�cula.\n";
	cout<<"\t2:\tBuscar aluno\n";
	cout<<"\t3:\tListar alunos ativos do curso.\n";
	cout<<"\t4:\tInserir aluno na pilha de remo��o.\n";
	cout<<"\t5:\tProcessar fila de matr�culas.\n";
	cout<<"\t6:\tEnviar alunos exclu�dos para an�lise do conselho.\n";
	cout<<"\t-1:\tSair\n";
	cin>>op;
	return op;
}

int main(){
	setlocale(LC_ALL,"");
	cout<<"Bem-vindo(a) ao sistema de cadastro de alunos!\n\n";
	
	list<Aluno> fila;
	list<Aluno> pilha;
	
	int m = 10;
	Aluno tabela_hash[m];
	
	for(int i=0;i<m;i++){
		tabela_hash[i].matricula = -1;
		tabela_hash[i].status = 0;
	}
	int op = 0;
	while(op != -1){
		op = menu();
		switch(op){
			case 1:
			{
				// Inserir aluno na fila
				Aluno novo = novo_aluno();
				fila.push_back(novo);
				break;
			}
			case 2: 
			{
				// Buscar aluno pela matr�cula
				int matricula;
				cout<<"Informa a matr�cula para buscar: ";
				cin>>matricula;
				int pos = buscar_aluno(tabela_hash, m, matricula);
				if(pos != -1){
					Aluno buscado = tabela_hash[pos];
					exibe_aluno(buscado);
				} else {
					cout<<"Aluno n�o encontrado"<<endl;
				}
				break;
			}
			case 3:
			{
				// Listar alunos de um determinado curso
				int curso = solicita_curso();
				lista_alunos_curso(tabela_hash, m, curso);
				break;
			}
			case 4:
			{				
				// Remover aluno pela matr�cula
				int matricula;
				cout<<"Informa a matr�cula para remover: ";
				cin>>matricula;
				int pos = buscar_aluno(tabela_hash, m, matricula);
				if(pos != -1){
					Aluno removido = tabela_hash[pos];
					pilha.push_front(removido);
				} else {
					cout<<"Aluno n�o encontrado"<<endl;
				}
				break;
			}
			case 5:
			{				
				// Processar fila de matr�culas
				while(!fila.empty()){
					Aluno novo = fila.front();
					int pos = insere_aluno(tabela_hash, m, novo);
					if(pos != -1){
						cout<<"Aluno inserido na posi��o "<<pos<<endl;
						fila.pop_front();
					}
					else{
						cout<<"Tabela cheia!";
						break;
					}
				}
				break;
			}
			case 6:
			{
				// Processa pilha de remo��es
				int processos = 0;
				while(processos < MAX_PROCESSOS_CONSELHO && !pilha.empty()){
					Aluno removido = pilha.front();
					exibe_aluno(removido);
					char confirma = 'n';
					cout<<"Tem certeza que quer remover o aluno acima? (s/n)";
					cin>>confirma;
					if(confirma == 's'){
						// Remover da tabela
						int pos = remover_aluno(tabela_hash, m, removido.matricula);
						if(pos != -1){
							cout<<"Aluno removido."<<endl;
						} else {
							cout<<"Erro ao remover aluno."<<endl;
						}						
					} else if(confirma == 'n') {
						cout<<"Aluno desconsiderado na remo��o."<<endl;
						
					} else {
						cout<<"Op��o inv�lida...";
						break;
					}
					// Remover da pilha
					pilha.pop_front();
					processos++;				
				}
				break;
			}
			case -1:
				break;				
			default:
				cout<<"Op��o inv�lida!"<<endl<<endl;
				break;
		}		
	}
	
	
	
	cout<<"\n\nObrigado por utilizar o sistema de cadastro de alunos!\n";
	
	return 0;
}




