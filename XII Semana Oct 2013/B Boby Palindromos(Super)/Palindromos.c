#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef size_t ll;

char frase[310] ;

void solve()
{
	int n = strlen(frase);
	char frase_bonita[310];

	frase_bonita[0] = '\0';

    int i, j;

	for (i = 0, j = 0; i < n; ++i)
	{
		if( isalpha(frase[i]) )
		{
			frase_bonita[j++] = frase[i];
			frase_bonita[j] = '\0';
		}
	}
	n = strlen(frase_bonita);
	//frase_bonita[n-1] = '\0';
	//n = strlen(frase_bonita);

	//cout << frase_bonita << '\n';

	//printf("%d\n", n);
	for ( i = 0, j = n-1; i < (n/2)+1; ++i, --j)
	{
		if(frase_bonita[i] != frase_bonita[j])
		{
			//printf("%d %d\n", i, j );
			printf("OH NO!\n");
			//printf("%s\n", frase_bonita);
			return;
		}
	}
    //printf("%s\n", frase_bonita);
	printf("NO SERAS COMIDO\n");
}

int main()
{
    //int k = 1;
	while(1)
	{
        fgets(frase, 310, stdin);
        if(frase[0] == 'H' && frase[1] == 'E' && frase[2] == 'C' && frase[3] == 'H' && frase[4] == 'O' )
            if(frase[5] == '\n' || frase[5] == '\0')
                break;

		//printf("%d", k++);
		solve();
	}

	return 0;
}

