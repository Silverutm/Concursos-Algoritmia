#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = i; i < n; i++)
		{
			if(v[i] > v[j])
			{
				int tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}

	for(int i=0; i < n; i++)
	{
		cout << v[i] << '\n';
	}

	return 0;
}