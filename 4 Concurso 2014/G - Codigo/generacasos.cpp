#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<ctime>
using namespace std;
int main()
{
	string auxC;
	srand(time(NULL));
	int M=rand()%50+1;
	int N=rand()%50+1;
	int x;
	
	for(int h=0;h<45;h++)
	{
		M=rand()%50+1;
		N=rand()%50+1;
		cout<<M<<" "<<N<<endl;
		for(int i = 0;i<M;i++)
		{
			for(int j =0;j < N;j++)
			{
				x=rand()%2;
				if(x)
				{
					auxC = 'A'+ ( rand() % ('Z' - 'A') );
				}
				else
				{
					auxC = 'a'+ ( rand() % ('z' - 'a') );
				}
				cout<<auxC;
			}
		}
		cout<<endl;
	}
	
	

	return 0;

}
