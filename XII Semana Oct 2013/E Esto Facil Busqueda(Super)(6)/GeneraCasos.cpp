#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	srand(time(NULL));
	freopen("Data.in","w",stdout);
	int a,n,t = 5000;
	cout<<t<<endl;
	while(t--)
    {
        n = rand()%400 +2;
        cout<<n<<endl;
        while(n--)
        {
            cout<<rand()%10000 +1<<" ";
        }
        cout<<endl<<rand()%20000 +1<<endl;
    }
}
