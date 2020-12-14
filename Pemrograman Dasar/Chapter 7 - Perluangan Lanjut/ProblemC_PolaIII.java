import java.util.Scanner;

public class PolaIII 
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		int numberOfRows = sc.nextInt();
		sc.close();
		int print = 0;
		for (int i = 1; i <= numberOfRows; i++)
		{	
			for (int k = 1; k <= i; k++)
			{
				System.out.print(print);
				print++;
				if (print == 10)
					print = 0;
			}
			System.out.println("");
		}
	}
}