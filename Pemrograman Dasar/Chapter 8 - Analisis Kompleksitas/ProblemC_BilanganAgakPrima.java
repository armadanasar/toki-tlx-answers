import java.util.Scanner;
import java.math.*;
public class SemiPrimeNumber
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
			
			System.out.println(checkSemiPrime(value));
			i++;
		}
		input.close();
	}

	static String checkSemiPrime(int value)
	{
		int i = 2;
		int otherDivisorCount = 0;
		boolean isPrime = true;
		
		if (value == 1)
			isPrime = true;
		//System.out.println((int)(Math.sqrt(value)));
		while ((i <= value/2 /*(int)(Math.sqrt(value))*/) && (isPrime) && (otherDivisorCount <= 2))
		{
			if (value % i == 0)
				otherDivisorCount++;
			i++;
		}
		
		
		String result = (otherDivisorCount <= 2) ? /*value + " " + */"YA" : /*value + " " + */"BUKAN";
		return result;
	}
}