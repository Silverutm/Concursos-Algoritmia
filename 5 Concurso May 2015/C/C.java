import java.util.*;

class Cmain
{
	public static void main(String[] args)
	{
		long C[][] = new long[205][205];
		int MOD = 1000000007;

		for(int i = 0; i <= 200; i++)
			for(int j = 0; j <= i; j++)
				C[i][j] = i == j || j == 0 ? 1 : (C[i-1][j] + C[i-1][j-1]) % MOD;

		Scanner sc = new Scanner(System.in);

		int tt = sc.nextInt();

		while (tt-- > 0)
		{
			int v[] = new int[30];
			String s = sc.next();

			int n = s.length();
			for(int i = 0; i < n; i++)
				v[s.charAt(i)-'a']++;

			long ans = 1;
			for(int i = 0; i < 'z'-'a'+1; i++)
			{
				if (v[i] > 0)
					ans = (ans*C[n][v[i]]) % MOD;
				n -= v[i];
			}

			System.out.println(ans);
		}
	}
}