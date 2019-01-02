import java.util.*;
import java.io.*;

class C
{
	public static void main(String[] args)
	{
		MyScanner sc = new MyScanner();
		int T = sc.nextInt();

		while (T > 0)
		{
			int N = sc.nextInt(), K = sc.nextInt();
			int[] sum = new int[1000005];

			sum[0] = 0;
			for(int i = 1; i <= N; i++)
			{
				sum[i] = sc.nextInt();
				sum[i] += sum[i-1];
			}

			int best = -1000000000, ind = 0;
			for(int i = K; i <= N; i++)
			{
				if (sum[i] - sum[i-K] > best)
				{
					best = sum[i] - sum[i-K];
					ind  = i - K + 1; 
				}
			}

			T--;
			System.out.println(ind + " " + best);
		}
	}
};

class MyScanner 
{
	BufferedReader br;
	StringTokenizer st;

	public MyScanner() 
	{
		br = new BufferedReader(new InputStreamReader(System.in));
	}

	String next() 
	{
		while (st == null || !st.hasMoreElements()) 
		{
			try 
			{
		 		st = new StringTokenizer(br.readLine());
			} 
			catch (IOException e) 
			{
			  	e.printStackTrace();
			}
		}
		return st.nextToken();
	}

	int nextInt() 
	{
		return Integer.parseInt(next());
	}

	long nextLong() 
	{
		return Long.parseLong(next());
	}

	double nextDouble() 
	{
		return Double.parseDouble(next());
	}

	String nextLine()
	{
		String str = "";
		try 
		{
			str = br.readLine();
		} 
		catch (IOException e) 
		{
			e.printStackTrace();
		}
		return str;
	}
};