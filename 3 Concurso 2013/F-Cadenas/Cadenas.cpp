#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define For(i, a, b) for(int i=a; i<b; ++i)
using namespace std;

bool isPalindromo(string A)
{
	int m1 = A.length()/2, m2 = A.length()/2;
	if (!(A.length()%2)) m1--;
	
	for(int i = m1, j = m2; i >= 0 and j < A.length(); i--, j++)
		if (A[i] != A[j]) return false;
	return true;
}

bool isEspejo(string A)
{
	char letra[] = {'A', 'E', 'H', 'I', 'J', 'L', 'M', 'O', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '5', '8'};
	char espej[] = {'A', '3', 'H', 'I', 'L', 'J', 'M', 'O', '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5', '1', 'S', 'E', 'Z', '8'};
	map <char, char> letraEsp;
	For(i, 0, 21)
		letraEsp[letra[i]] = espej[i];
		
	int m1 = A.length()/2, m2 = A.length()/2;
	if (!(A.length()%2)) m1--;
	
	for(int i = m1, j = m2; i >= 0 and j < A.length(); i--, j++)
		if (A[j] != letraEsp[A[i]]) return false;
	return true;
}

bool isPalEsp(string A)
{
	char letra[] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y', '1', '8'};
	bool sirve[26];
    memset(sirve, 0, sizeof sirve);
	For(i, 0, 13)
		sirve[letra[i]-'A'] = true;
	
	int m1 = A.length()/2, m2 = A.length()/2;
	if (!(A.length()%2)) m1--;
	for(int i = m1, j = m2; i >= 0 and j < A.length(); i--, j++)
		if (A[i] != A[j] or (A[i] == A[j] and !sirve[A[i]-'A'])) return false;
	return true;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M, P, valor[15] = {0}, nEsp[15] = {0};
        memset(valor, 0, sizeof valor);
        memset(nEsp, 0, sizeof nEsp);
		vector <vector <string> > utiles;
		string palabra[15];
		cin>>M>>P;
		utiles.assign(M, vector<string> ());
		For(i, 0, M)
		{
			int indice[60];
			cin>>palabra[i];
			For(k, 0, P)
				cin>>indice[k];
			int pos = 0;
			For(k, 0, P)
			{
				string A = "";
				For(j, pos, indice[k]+1)
					A = A + palabra[i][j];
				//cout<<A<<endl;
				pos = indice[k]+1;
				if (isPalEsp(A))
				{
					valor[i] += 3;
					utiles[i].push_back(A);
					nEsp[i]++;
				}
				else if (isEspejo(A))
				{
					valor[i] += 2;
					utiles[i].push_back(A);
				}
				else if (isPalindromo(A))
				{
					valor[i] += 1;
					utiles[i].push_back(A);
				}
			}
		}
		int mayor = 0;
		For(i, 0, M)
			if (valor[i] > valor[mayor])
				mayor = i;
		sort(utiles[mayor].begin(), utiles[mayor].end());
		cout<<palabra[mayor]<<endl;
		cout<<nEsp[mayor]<<" "<<valor[mayor]<<endl;	
		For(j, 0, utiles[mayor].size())
			cout<<utiles[mayor][j]<<endl;	 
	}
	return 0;
}
