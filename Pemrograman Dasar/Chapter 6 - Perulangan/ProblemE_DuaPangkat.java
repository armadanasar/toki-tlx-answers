import java.util.Scanner;
import java.math.*;
public class DuaPangkat 
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		int value = input.nextInt();
		int checker = 1;
		input.close();
		
		while (checker < value)
		{
			checker*=2;
		}
		
		if (checker == value) 
			System.out.println("ya");
		else		
			System.out.println("bukan");
	}
}