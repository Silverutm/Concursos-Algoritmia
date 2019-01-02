#include <iostream>

using namespace std;
int l[10000][10000];
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int C;
	cin >> C;

	for (int i = 0; i < C; i++) {
		int n, m;
		cin >> n >> m;
		n = n-1;
		m = m-1;
			
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					l[j][k]=(k+1)*(j+1);
				}
			}
			int sumagrande = 0;
			for (int j = 0; j < n; j++) {
				int sumachica = 0;
				for (int k = 0; k < m; k++) {
					sumachica += l[j][k];
				}
				sumagrande += sumachica;
			}
			cout << sumagrande << "\n";
	}
    return 0;
}
