#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;

long long intervalo (long long a, long long b) {
	if (b == 0) return 0;
	return rand() % (b - a + 1) + a;
}

int main(int argc, char const *argv[])
{
	srand (time(NULL));
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
			freopen(outputFileName.c_str(), "w", stdout);
			int t = intervalo(1, limtitTestCases);
			cout << t << endl;
			long long n, inicio, final;
			while (t--) {

				if (caso == 0) n = intervalo(1, limitCasoC);
				if (caso == 1) n = intervalo(10, limitCasoM);
				if (caso == 2) n = intervalo(1000, limitCasoG);
				cout << n << endl;
				
				while (n--) {
					final = intervalo(1, limitF);
					inicio = intervalo(0, final - 1);
					cout << inicio << " " << final << endl; 
				}
			}

			fclose(stdout);
		}
	}
	return 0;
}