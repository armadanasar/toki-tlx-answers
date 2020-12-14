import java.util.Scanner;
public class FaktorBilangan 
{

	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		int value = input.nextInt();
		int i = 1;
		input.close();
		
		while (i <= value)
		{
			//if (i == 1)
			//{
			//	i++;
			//	continue;
			//}
			if (value % i == 0)
				System.out.println(value/i);
			i++;
		}
	}
}