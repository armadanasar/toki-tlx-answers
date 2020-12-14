import java.util.Scanner;

public class PerkalianMatrix 
{

	public static void main(String[] args) 
	{
		int matrixOneRows = 0;
		int matrixOneColumnsAndMatrixTwoRows = 0;
		int matrixTwoColumns = 0;
		
		Scanner sc = new Scanner(System.in);
		matrixOneRows = sc.nextInt();
		matrixOneColumnsAndMatrixTwoRows = sc.nextInt();
		matrixTwoColumns = sc.nextInt();
		
		int[][] matrixOne = new int[matrixOneRows][matrixOneColumnsAndMatrixTwoRows];
		int[][] matrixTwo = new int[matrixOneColumnsAndMatrixTwoRows][matrixTwoColumns];
		int[][] result = new int[matrixOneRows][matrixTwoColumns];
		
		for (int i = 0; i < matrixOneRows; i++)
		{
			for (int j = 0; j < matrixOneColumnsAndMatrixTwoRows; j++)
				matrixOne[i][j] = sc.nextInt();
		}
		
		for (int i = 0; i < matrixOneColumnsAndMatrixTwoRows; i++)
		{
			for (int j = 0; j < matrixTwoColumns; j++)
				matrixTwo[i][j] = sc.nextInt();
		}
		
		/*for (int i = 0; i < matrixOneRows; i++)
		{
			for (int j = 0; j < matrixOneColumnsAndMatrixTwoRows; j++)
				System.out.print(matrixOne[i][j] + " ");
			System.out.println("");
		}
		
		for (int i = 0; i < matrixOneColumnsAndMatrixTwoRows; i++)
		{
			for (int j = 0; j < matrixTwoColumns; j++)
				System.out.print(matrixTwo[i][j] + " ");
			System.out.println("");
		}*/
		
		for (int i = 0; i < matrixOneRows; i++)
			for (int j = 0; j < matrixTwoColumns; j++)
				result[i][j] = 0;
		
		for (int i = 0; i < matrixOneRows; i++)
			for (int j = 0; j < matrixTwoColumns; j++){
				int total = 0;
				for (int k = 0; k < matrixOneColumnsAndMatrixTwoRows; k++)
					total = total + (matrixOne[i][k] * matrixTwo[k][j]);
				result[i][j] = total;
			}
		for (int i = 0; i < matrixOneRows; i++)
		{
			for (int j = 0; j < matrixTwoColumns; j++)
			{
				if (j == matrixTwoColumns-1)
					System.out.print(result[i][j]);
				else
					System.out.print(result[i][j] + " ");
			}
			System.out.println("");
		}
		sc.close();

	}

}