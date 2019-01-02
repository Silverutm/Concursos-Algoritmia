#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;

struct triple{
	int x,y,z;
};

bool operator<(const triple& a, const triple& b){
	if(a.x==b.x){
		if(a.y==b.y){
			return a.z < a.z;
		}
		return a.y < b.y;
	}
	return a.x < b.x;
}

vector<int> divisores(int n){
	vector<int> divisores;
	int limit=sqrt(n);
	for(int i=1; i<=limit; i++){
		if(!(n%i)){
			divisores.push_back(i);
			if(i!=(n/i)) divisores.push_back(n/i);
		}
	}
	return divisores;
}

triple make_tripe(int* arr){
	triple aux;
	sort(arr,arr+3);
	aux.x = arr[0];
	aux.y = arr[1];
	aux.z = arr[2];
	return aux;
}

int main(){
	int arr[3];
	int N,M,i;
	scanf("%d",&N);
	while(N--){
		set<triple> solu;
		scanf("%d",&M);
		vector<int> divi = divisores(M);
		for(int d=0; d<divi.size(); d++){
			vector<int> divi2 = divisores(M/divi[d]);
			for(i=0; i<divi2.size();i++){
				arr[0] = divi[d];
				arr[1] = divi2[i];
				arr[2] = M/(arr[0]*arr[1]);
				solu.insert(make_tripe(arr));
			}
		}
		//Imprimir soluciones
		printf("# %d:\n",M);
		for(set<triple>::iterator it=solu.begin(); it!=solu.end();it++){
			printf("(%d,%d,%d)\n",it->x,it->y,it->z);
		}
	}
	return 0;
}