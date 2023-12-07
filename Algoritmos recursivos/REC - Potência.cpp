#include <iostream>

using namespace std;

int pot(int a, int n)
{
	int res =1 ;

	if(n == 0) // a^n = 1 se n = 0
	{
		return 1;
	}
	if(n > 0) // a·an-1 se n>0
	{
		res = a*pot(a,n-1);//fala isso no enunciado, res chama a função pot
	}
	
	return res;
}

int main()
{
	int a;
	int n;
	
	cin >> a >> n;
	while(n < 0)
	{
		cin >> n;
	}
	
	cout << pot(a,n) << endl;
	
	
	return 0;
}
// recursividade é uma função que chama a si mesma