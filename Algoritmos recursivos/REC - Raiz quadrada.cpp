#include <iostream>
#include <cmath>

using namespace std;

double raiz(int x, double x0, double epsilon){  //raiz quadrada com recursão
    
    // caso base: verifica se a diferença entre o quadrado da estimativa e o número original é menor ou igual a epsilon
    if(abs(x0 * x0 - x) <= epsilon) // abs= valor absoluto sem sinal
        return x0;
    else
        return raiz(x, (x0 * x0 + x) / (2.0 * x0), epsilon);//formula no enunciado
}

int main(int argc, const char * argv[]) {
    int x;
    double epsilon, x0;
    
    cin >> x;
    cin >> x0;
    cin >> epsilon;
    
    //chama a função da raiz quadrada com recursão
    double result = raiz(x, x0, epsilon);// raiz e seus "argumentos"
    
    cout << result << endl;
    
    return 0;
}