import java.util.Scanner;

public class For //extends java.lang.Object 
{
	public static void main(String[] args)
	{
		int items = 0;
		int result = 0;
		int looper = 0;
		String inputBuf = "";
		
		
		Scanner input = new Scanner(System.in);
		items = input.nextInt();
		//force the feed to see the next line! yeah, I/O sucks as hell!
		input.nextLine();
		inputBuf = input.nextLine();
		input.close();
		
		//main loop init
		String inputArray[] = new String[items];
		inputArray = inputBuf.split(" ");
		
		//result += Integer.parseInt(inputArray[0]);
		
		while (looper < items)
		{
			result+=Integer.parseInt(inputArray[looper]);
			looper++;
		}
		
		System.out.println(result);
	}
}