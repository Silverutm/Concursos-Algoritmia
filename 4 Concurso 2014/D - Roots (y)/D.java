import java.util.*;
import java.io.*;

class D
{
	public static void main(String[] args)
	{
		MyScanner sc = new MyScanner();
		int T = sc.nextInt();

		while (T-- > 0)
		{
			int k = sc.nextInt(), d = sc.nextInt();

			for(int i = 0; i < k-1; i++)
				System.out.print(9);
			System.out.println(d);

			if (k > 1)
				System.out.print(1);
			for(int i = 1; i < k-1; i++)
				System.out.print(0);
			if (k > 1)
				System.out.println(d-1);
			else
				System.out.println(d);
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