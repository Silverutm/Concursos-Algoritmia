#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<ctime>
using namespace std;

int main()
{
	int M, N;
	cout << "10000" << endl;
	for(int i = 0; i < 10000; i++)
	{
		M = rand() % 40000+1;
		N = rand() % 40000+1;
		while(M == N)
		{
			M = rand() % 40000+1;
			N = rand() % 40000+1;
		}
		cout << M << " " << N << endl;
	}
	return 0;
}
