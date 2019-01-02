import java.util.*;

class Cmain
{
	static class pair
	{
		public int x, y;
		public pair(int _x, int _y)
		{
			x = _x;
			y = _y;
		}
	}

	static int dX[] = {-2, -1, 1, 2, 2, 1, -1, -2}, dY[] = {1, 2, 2, 1, -1, -2, -2, -1};

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int tt = sc.nextInt();

		while (tt-- > 0)
		{
			int n = sc.nextInt(), m = sc.nextInt();
			String board[] = new String[n];

			sc.nextLine();
			for (int i = 0; i < n; ++i)
				board[i] = sc.nextLine();

			int xf = sc.nextInt(), yf = sc.nextInt();
			xf = n-xf;
			--yf;

			int dist[][] = new int[n][m];
			Queue<pair> cola = new LinkedList<pair>();

			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
					if (board[i].charAt(j) == 'c')
					{
						cola.add(new pair(i, j));
						dist[i][j] = 1;
					}

			while (!cola.isEmpty())
			{
				pair act = cola.remove();

				if (act.x == xf && act.y == yf)
					break;

				for (int k = 0; k < 8; ++k)
				{
					int nx = act.x+dX[k], ny = act.y+dY[k];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx].charAt(ny) != '*' || dist[nx][ny] != 0)
						continue;

					cola.add(new pair(nx, ny));
					dist[nx][ny] = dist[act.x][act.y] + 1;
				}
			}

			System.out.println(dist[xf][yf]-1);
		}
	}
}