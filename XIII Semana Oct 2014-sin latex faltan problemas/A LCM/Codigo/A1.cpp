#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, a, b, aux, cont;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		aux = min(a, b);
		b = max(a, b);
		a = aux;
		cont = 1;
		while((a % b) != 0)
		{
			cont++;
			
			a+= aux;
			//if (a > 0)
				//cout << a << endl;
		}
		//cout << endl << cont << endl;
		cout << a << endl;
		
	}
	return 0;
}
