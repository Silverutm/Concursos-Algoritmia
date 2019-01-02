#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	string outputFileName = "";
	int limitCasoC = 100;
	int limitCasoM = 1000000;
	long long limitCasoG = 1000000000000000000;
	int limtitTestCases = 100;
	int limitKC = 4;
	int limitKM = 8;
	int limitKG = 32;

	for (int caso = 0; caso < 3; ++caso)
	{
		for (int input = 0; input < 10; ++input)
		{
			caso == 0 ? outputFileName = 'C' : caso == 1 ? outputFileName = 'M' : outputFileName = 'G';
			outputFileName += to_string(input);
			outputFileName += ".in";
			freopen(outputFileName.c_str(), "r", stdin);
			int t;
			cin >> t;
			if (t > 100 or t < 1)
			{
				cout << "ERROR file " << outputFileName << endl; 
			}
			long long n, m, k;
			while (t--) {
				cin >> n >> m >> k;
				if (caso == 0) {
					if ((n > limitCasoC or n < 1) or (m < 1 or m > limitCasoC) or (k < 1 or k > limitKC)) {
						cout << "ERROR file " << outputFileName << endl;
						fclose(stdin);
						return 0; 
					}
				}
				if (caso == 1) {
					if ((n > limitCasoM or n < 1) or (m < 1 or m > limitCasoM) or (k < 1 or k > limitKM)) {
						cout << "ERROR file " << outputFileName << endl; 
						fclose(stdin);
						return 0; 
					}
				}
				if (caso == 2) { 
					if ((n > limitCasoG or n < 1) or (m < 1 or m > limitCasoG) or (k < 1 or k > limitKG)) {
						cout << "ERROR file " << outputFileName << endl; 
						fclose(stdin);
						return 0; 
					}
				}
			}
			fclose(stdin);
		}
	}
	cout << "Bien" << endl;
	return 0;
}