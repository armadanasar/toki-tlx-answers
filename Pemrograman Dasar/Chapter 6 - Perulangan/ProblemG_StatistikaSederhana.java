import java.util.Scanner;
public class StatistikaSederhana 
{
	public static void main(String[] args)
	{
		int items = 0;
		int buffer, lowest, highest;
		int looper = 1;
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
		
		buffer = Integer.parseInt(inputArray[0]);
		lowest = buffer;
		highest = buffer;
		
		while (looper < items)
		{
			buffer = Integer.parseInt(inputArray[looper]);
			if (buffer > highest)
				highest = buffer;
			else if (buffer < lowest)
				lowest = buffer;
			looper++;
		}

		System.out.println(highest + " " + lowest);
	}
}