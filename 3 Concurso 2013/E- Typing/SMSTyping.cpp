#include <iostream>
#include <cstdio>
#define For(i, a, b) for(int i=a; i<b; ++i)
using namespace std;

int main()
{	
	int T[26];
	for (int i=0, v=0; i<26; i++)
	{
		if (i+'a' == 's' or i+'a' == 'z')
			T[i] = 4;
		else
		{
			T[i] = v+1;
			v = (v+1)%3;
		}
	}
	
	int casos;
	string basura;
	cin>>casos;
	getline(cin, basura);
	For(j, 0, casos)
	{
		int total = 0;
		string L = "";
		getline(cin, L);
		For(i, 0, L.length())
			if (L[i] == ' ') total++;
			else total += T[L[i]-'a'];
		cout<<"Case #"<<j+1<<": "<<total<<endl;
	}
	return 0;
}
