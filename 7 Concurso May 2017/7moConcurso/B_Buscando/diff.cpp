#include <bits/stdc++.h>
using namespace std;
int main()
{//				  		  0123456789012345678901
	char instruccion[] = "diff C3.outI1 C3.outM2";
	for (int l = 0; l < 2; ++l)	
	{
		for (char k = '0'; k <= '9'; ++k)
		for (char i = '1'; i <= '2'; ++i)	//M-1-
		for (char j = i + 1; j <= '3'; ++j)	//M-2-
		{
			if (l==0) {instruccion[5] = 'C'; instruccion[14] = 'C';}
			else if (l==1) {instruccion[5] = 'M'; instruccion[14] = 'M';}
			else {instruccion[5] = 'G'; instruccion[14] = 'G';}

			instruccion[6] = instruccion[15] = k;
			instruccion[12] = i;
			instruccion[21] = j;
			instruccion[12] = ' ';

			system(instruccion);
		}
	}
	return 0;
}