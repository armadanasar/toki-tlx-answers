import java.util.Scanner;

public class WhilePencacah 
{

	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		int result = 0;
		while (true)
		{
			String buf = input.nextLine();
			result += Integer.parseInt(buf);
			
			if (!input.hasNext())
			{
				System.out.println(result);
				break;
			}
			
		}
		input.close();
	}
}