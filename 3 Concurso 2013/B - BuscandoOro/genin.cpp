#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#define For(i, a, b) for(int i=a; i<b; ++i)
using namespace std;
int main()
{
	srand(time(NULL));
	int T = 20;
	cout<<T<<endl;
	For(k, 0, T)
	{
		int R = (rand()%20)+1, C = (rand()%20)+1, gold = 0;
		int x = rand()%C, y = rand()%R; 
		bool done;
		cout<<R<<" "<<C<<endl;
		For(i, 0, R)
		{
			For(j, 0, C)
			{
				if (i == y  and j == x)
					cout<<'x';
				else if (rand()%100 < 95 or gold == 15)
					cout<<'.';
				else
				{
					cout<<'g';
					gold++;
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
