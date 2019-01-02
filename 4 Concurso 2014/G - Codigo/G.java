import java.util.Scanner;

class G
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for(int k = 0; k < T; k++)
		{
			int M = sc.nextInt();
			int N = sc.nextInt();
			sc.nextLine();
			String S = sc.nextLine();

			for(int i = M-1; i >= 0; i--)
	        {
	            for(int j = 0; j < N; j++)
	            {
	            	//System.out.println(i+M*j);
	                System.out.print(S.charAt(i+M*j));
	            }
	        }	
	        System.out.print("\n");
		}
	}
};