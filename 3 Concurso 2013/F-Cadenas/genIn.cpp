#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#define For(i, a, b) for(int i=a; i<b; ++i)
using namespace std;

string palindromo()
{
	int t = (rand()%100)+1;
	string A = "";
	For(i, 0, t)
		if (rand()%2)
			A = A + (char)(rand()%10 + '0');
		else
			A = A + (char)(rand()%26 + 'A');

	For(i, rand()%2, t)
		A = A + A[t-1-i];
	return A;
}

string espejo()
{
	char letra[] = {'A', 'E', 'H', 'I', 'J', 'L', 'M', 'O', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '5', '8'};
	char espej[] = {'A', '3', 'H', 'I', 'L', 'J', 'M', 'O', '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5', '1', 'S', 'E', 'Z', '8'};
	int t = (rand()%100) + 1;
	map <char, char> letraEsp;
	For(i, 0, 21)
		letraEsp[letra[i]] = espej[i];
	string A = "";
	For(i, 0, t)
		A = A + (char)(letra[rand()%21]);
	For(i, rand()%2, t)
		A = A + letraEsp[A[t-1-i]];
	return A;
}

string palEspejo()
{
	char letra[] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y', '1', '8'};
	int t = (rand()%100) + 1;
	string A = "";
	For(i, 0, t)
		A = A + letra[rand()%13];
	For(i, rand()%2, t)
		A = A + A[t-1-i];
	return A;
}

string basura()
{
	int t = (rand()%100) + 1;
	string A = "";
	For(i, 0, t)
		A = A + (char)((rand()%26) + 'A');
	return A;
}

int main()
{
	srand(time(NULL));
	int T = 100;
	//cout<<palindromo()<<endl;
	cout<<T<<endl;
	while(T--)
	{
		int M = (rand()%10)+1, P = (rand()%50)+1;
		cout<<M<<" "<<P<<endl;
		For(i, 0, M)
		{
			int ind[50], t = rand()%4;
			For(j, 0, P)
			{
				string A;
				if (t == 0)
					A = palindromo();
				else if (t == 1)
					A = espejo();
				else if (t == 2)
					A = palEspejo();
				else 
					A = basura();
				cout<<A;
				if (j > 0)
					ind[j] = A.length() + ind[j-1];
				else 
					ind[j] = A.length()-1;
			}
			cout<<endl;
			For(j, 0, P)
				cout<<ind[j]<<" ";
			cout<<endl;
		}
	}
}
