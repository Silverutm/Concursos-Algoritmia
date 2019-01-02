#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <cctype>
#include <vector>
#include <map>
#include <cctype>

using namespace std;

typedef size_t ll;

string frase ;
void solve()
{
	int n = frase.size();
	string frase_bonita = "";

	for (int i = 0; i < n; ++i)
	{
		if(not (frase[i] == '.' or frase[i] == ',' or frase[i] == '!' or frase[i] == '?' or frase[i] == ' ' or frase[i] == '\n') )
		{
		//if(isalpha(frase[i]))
			frase_bonita += frase[i];
		}
	}

	n = frase_bonita.size();


	for (int i = 0, j = n-1; i < (n/2)+1; ++i, --j)
	{
		if(frase_bonita[i] != frase_bonita[j])
		{
			//cout << frase_bonita[i] << " " << frase_bonita[j] << '\n';
			printf("OH NO!\n");
			return;
		}
	}
	printf("NO SERAS COMIDO\n");
}

int main()
{
    //int k = 1;
	while(getline(cin, frase) and frase != "HECHO")
	{
		solve();
	}

	return 0;
}

