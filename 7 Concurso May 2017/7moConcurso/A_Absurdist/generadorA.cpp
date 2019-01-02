#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;

random_device rd;
mt19937 gen(rd());

long long intervalo (long long a, long long b) {
	uniform_int_distribution <unsigned long long> rand_interval(a, b);
	return rand_interval(gen);
}

int main(int argc, char const *argv[])
{
	srand (time(NULL));
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
			freopen(outputFileName.c_str(), "w", stdout);
			int t = intervalo(1, limtitTestCases);
			cout << t << endl;
			long long n, m, k;
			while (t--) {
				if (caso == 0) n = intervalo(1, limitCasoC), m = intervalo(1, limitCasoC), k =intervalo(1, limitKC);
				if (caso == 1) n = intervalo(1, limitCasoM), m = intervalo(1, limitCasoM), k =intervalo(1, limitKM); 
				if (caso == 2) n = intervalo(1, limitCasoG), m = intervalo(1, limitCasoG), k =intervalo(1, limitKG);
				cout << n << " " << m << " " << " " << k << endl;
			}

			fclose(stdout);
		}
	}
	return 0;
}