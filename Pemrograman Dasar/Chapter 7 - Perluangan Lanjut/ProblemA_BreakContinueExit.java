import java.util.Scanner;

public class BreakContinueExit 
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		int numberOfIterations = sc.nextInt();
		sc.close();

		for (int i = 1; i <= numberOfIterations; i++ )
		{
			if (i % 10 == 0)
				continue;
			if (i == 42)
			{
				System.out.println("ERROR");
				break;
			}
			
			System.out.println(i);
		}
	}
}