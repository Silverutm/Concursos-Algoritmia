//188888881, 777767777, 700666007
//933101339 987101789 996808699 986444689 989646989
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 188888881

struct Matrix { ll mat[2][2]; };
Matrix matMul(Matrix a, Matrix b) 
{
    Matrix ans; int i, j, k;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            for (ans.mat[i][j] = k = 0; k < 2; k++)
                ans.mat[i][j] = (ans.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % mod;
    return ans; 
}

Matrix matPow(Matrix base, ll p) 
{

    Matrix ans; int i, j;
    for (i = 0; i < 2; i++) 
        for (j = 0; j < 2; j++)
            ans.mat[i][j] = (i == j);
    
    while (p) 
    {
        if (p & 1) 
        ans = matMul(ans, base);
        base = matMul(base, base);
        p >>= 1;
    }
    return ans; 
}

Matrix fibonacha;

int main()
{
    fibonacha.mat[0][0] = 1; fibonacha.mat[0][1] = 1; fibonacha.mat[1][0] = 1; fibonacha.mat[1][1] = 0;
    
    int t;
    ll n;
    cin>>t;
    while (t--)
    {
        cin>>n;        
        auto res = matPow(fibonacha, n);
        cout<< res.mat[0][0] * res.mat[0][1] % mod<<"\n";
    }
    return 0;
}