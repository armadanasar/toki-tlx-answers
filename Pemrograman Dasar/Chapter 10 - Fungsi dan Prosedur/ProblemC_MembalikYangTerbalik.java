import java.util.Scanner;

public class MembalikYangTerbalik 
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int y = sc.nextInt();
		sc.close();
		//System.out.println(reverseNumber(x) + " " + reverseNumber(y));
		System.out.println(reverseAdd(x, y) + "");
	}

	static int reverseAdd(int param1, int param2)
	{
		return reverseNumber(reverseNumber(param1) + reverseNumber(param2));
	}
	
	static int reverseNumber(int input)
	{
		int temp = input;
		int result = 0;
		
		while (temp > 0)
		{
			result = (result * 10) + (temp % 10);
			temp = temp/10;
		}
		
		return result;
	}
}