#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T,i=0,aux1,aux2;
	int k,j,p=0;
	multiset<int> x;
	multiset<int> y;
	vector<int> v1;
	vector<int> v2;
	scanf("%d",&T);
	vector<int> banderas;
	while(i<T){
		scanf("%d",&k);
		p=0;
		while(p<k){
			scanf("%d %d",&aux1,&aux2);
		    v1.push_back(aux1);
			v2.push_back(aux2);
			x.insert(aux1);
			y.insert(aux2);
			p++;
		}
		for(j=0; j<k;j++)
		{
			if(v1[j]==v2[j]){
				banderas.push_back(1);
				break;
				}
			else
			{
				if(x.count(v1[j])>=2||y.count(v2[j])>=2)
				{
					banderas.push_back(1);
					break;
				}else
				{
					banderas.push_back(0);
					break;
				}
			}
		}
		v1.clear();
		v2.clear();
		x.clear();
		y.clear();
		i++;	
	}
	for(j=0; j<T; j++){
		if(banderas[j]==0)
			printf("Intercambio exitoso.\n");
		else
			printf("Papelitos otra vez.\n");
	}
	return 0;
}