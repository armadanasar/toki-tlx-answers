import java.util.Scanner;

public class RotasiMatriks 
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		int baris = sc.nextInt();
		int kolom = sc.nextInt();
		
		
		int[][] matrix = new int[baris][kolom];
		//int[][] rotatedMatrix = new int[kolom][baris];
		
		for (int i = 0; i < baris; i++)
		{
			for (int j = 0; j < kolom; j++)
			{
				matrix[i][j] = sc.nextInt();
			}
			
		}
		
		/*for (int i = 0; i < baris; i++)
		{
			for (int j = 0; j < kolom; j++)
			{
				System.out.print(matrix[i][j] + " ");
			}
			System.out.println("");
		}*/
		
		for (int i = 0; i < kolom; i++)
		{
			for (int j = baris-1; j >= 0; j--)
			{
				if (j == 0) System.out.print(matrix[j][i]);
				else System.out.print(matrix[j][i] + " ");
			}
			System.out.println("");
		}
		
		sc.close();
	}
}