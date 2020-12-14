import java.util.Scanner;
import java.math.*;
public class CekBilanganPrima 
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		int items = input.nextInt();
		int i = 0;
		String inputBuf;
		input.nextLine();
		
		while (i < items)
		{
			inputBuf = input.nextLine();
			int value = Integer.parseInt(inputBuf);
			
			System.out.println(checkPrime(value));
			i++;
		}
		input.close();
	}

	static String checkPrime(int value)
	{
		int i = 2;
		boolean isPrime = true;
		
		if (value == 1)
			isPrime = false;
		
		while ((i <= (int)(Math.sqrt(value))) && (isPrime))
		{
			if (value % i == 0)
				isPrime = false;
			i++;
		}
		
		
		String result = (isPrime) ? /*value + " " + */"YA" : /*value + " " + */"BUKAN";
		return result;
	}
}