import java.util.Scanner;

class B
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		while (T > 0)
		{
			int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();

			if (a == 0)
			{
				if (b == 0)
				{
					if (c == 0)
						System.out.println("Negro");
					else
						System.out.println("Naranja");
				}
				else
				{
					if (c == 0)
						System.out.println("Verde");
					else
						System.out.println("Amarillo");
				}
			}
			else
			{
				if (b == 0)
				{
					if (c == 0)
						System.out.println("Morado");
					else
						System.out.println("Rojo");
				}
				else
				{
					if (c == 0)
						System.out.println("Azul");
					else
						System.out.println("Blanco");
				}
			}

			T--;
		}
	}
};