#include <bits/stdc++.h>
using namespace std;

typedef pair <long long,long long> ii;
typedef vector <ii> vii;

bool f(ii a, ii b)
{
	if(a.second<=b.second)
		return true;
	else 
		return false;
}

int main(int argc, char const *argv[])
{
	vii intervalos;
	long long a,b;
	int c;
	//cin >> c;
	scanf("%d", &c);
	vii aux;
	while (c--)
	{
		long long n;
		scanf("%lld", &n);
		//cin >> n;
		intervalos.clear();
		while(n--)
		{
			scanf("%lld %lld", &a, &b);
			//cin>>a>>b;
			intervalos.push_back(make_pair(a,b));
		}
		
		sort(intervalos.begin(), intervalos.end(),f);
		continue;
		aux.clear();

		aux.push_back(intervalos[0]);
		//cout<<"llegue\n";


		for (int j = 1; j < intervalos.size(); j++)
		{
			if(intervalos[j].first>=aux[aux.size()-1].second)
			{
				aux.push_back(intervalos[j]);
			}		
		}

		printf("%d\n", (int)aux.size());
		//return 0;
	}
	
	return 0;
}