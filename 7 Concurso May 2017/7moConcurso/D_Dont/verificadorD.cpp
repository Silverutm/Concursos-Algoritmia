#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	string outputFileName = "";
	int limitCasoC = 10;
	int limitCasoM = 100;
	long long limitCasoG = 100000;
	int limtitTestCases = 20;
	int limitF = 1000;


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
			if (t > limtitTestCases or t < 1)
			{
				cout << "ERROR file " << outputFileName << endl; 
			}
			long long n, inicio, final;
			while (t--) {
				cin >> n;
				if (caso == 0) {
					if (n > limitCasoC or n < 1) {
						cout << "ERROR file " << outputFileName << endl;
						fclose(stdin);
						return 0; 
					}
				}
				if (caso == 1) {
					if (n > limitCasoM or n < 1) {
						cout << "ERROR file " << outputFileName << endl; 
						fclose(stdin);
						return 0; 
					}
				}
				if (caso == 2) { 
					if (n > limitCasoG or n < 1) {
						cout << "ERROR file " << outputFileName << endl; 
						fclose(stdin);
						return 0; 
					}
				}

				while (n--) {
					cin >> inicio >> final;
					if ((inicio >= final) or inicio < 0 or final > limitF) {
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