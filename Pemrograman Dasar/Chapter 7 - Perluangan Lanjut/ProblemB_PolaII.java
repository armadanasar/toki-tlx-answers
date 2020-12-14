import java.util.Scanner;

public class PolaII 
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		int numberOfRows = sc.nextInt();
		sc.close();
		
		for (int i = 1; i <= numberOfRows; i++)
		{
			for (int j = numberOfRows - i; j > 0; j--)
			{
				System.out.print(" ");
			}
			
			for (int k = 1; k <= i; k++)
			{
				System.out.print("*");
			}
			System.out.println("");
		}

	}

}