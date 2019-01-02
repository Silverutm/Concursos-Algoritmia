#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iterator>

using namespace std;

bool
ispali (string &s)
{
  string copy = s;
  reverse (copy.begin(),copy.end());

  if (s == copy)
    return true;

  return false;
}

int f[1000009];
int es_palindromo(int n)
{
  int c=n, p;
  p=0;
  while (n)
  {
    p *= 10;
    p += n%10;
    n /= 10;
  }
  return p==c;
}


 




int
main ()
{
  
  //int a, n, b;
  f[0]=1;
  for (int i = 1; i < 1000006; ++i)
    f[i] = f[i-1]+ es_palindromo(i);


  size_t len;
  size_t cases;
  size_t i;
  char number [8]; 
  unsigned npal,a,b;
  string current;
  vector <unsigned> palindromes;
  unsigned count = 0;

  palindromes.push_back (0);
  for (i = 1; i <= 1000000; ++i)
    {
      current.clear();
      len = sprintf (number,"%lu",i); 
      for (int j = 0; j < len; ++j)
        current.push_back(number[j]);

      if (ispali (current))
      {
        palindromes.push_back (++count);
      }
      else
      {
        palindromes.push_back (count);
      }
    }

  cin >> cases;
  while (cases--)
  {
    cin >> a >> b;
    if (a >= b)
     swap (a,b);
   int res=0,res1=0;
    if (palindromes[a] > palindromes[a-1] ||
            palindromes[b] > palindromes[b-1]) 
            {
                  res=palindromes[b] - palindromes[a] + 1 ;
                  cout << palindromes[b] - palindromes[a] + 1 << endl;
            }
    else
    {
                res=palindromes[b] - palindromes[a];
                  cout << palindromes[b] - palindromes[a] << endl;
    }
    res1 = f[b]-f[a-1];
    cout<<f[b]-f[a-1]<<endl;
    if (res1!=res) cout<<"Hate you Nigga\n";
    cout<<endl;
  }
  
  return 0;
}


