import java.util.Arrays;
import java.util.Scanner;

public class ModusTerbesar 
{
	public static void main(String[] args) 
	{
		int items = 0;
		String inputBuf = "";
		
		Scanner input = new Scanner(System.in);
		items = input.nextInt();
		input.nextLine();
		inputBuf = input.nextLine();
		input.close();
		
		String[] inputArray = new String[items];
		inputArray = inputBuf.split(" ");
		
		int[] values = new int[items];
		for (int i = 0; i < items; i++)
		{
			values[i] = Integer.parseInt(inputArray[i]);
		}
		
		Arrays.sort(values);
		/*if (isUnique (values))
		{
			System.out.println("0");
			return;
		}*/
		/*for (int x : values)
		{
			System.out.print(x + " ");
		}
		System.out.println("");*/
		int currentModeCounter = 0;
		int mode = 0;
		int prevModeCounter = 0;
		int prevMode = 0;
		mode = values[0];
		currentModeCounter++;
		for (int i = 1; i < items; i++)
		{
			if (values[i] == values[i-1])
				currentModeCounter++;
			else if (values[i] != values[i-1])
			{
				/*if (currentModeCounter == prevModeCounter)
				{
					int temp = Math.max(mode, prevMode);
					mode = temp;
					continue;
				}*/
				
				//If we encounter another number, check whether the current mode count is higher than the saved previous one. if so, then you can safely update the values.
				if (currentModeCounter >= prevModeCounter)
				{
					prevModeCounter = currentModeCounter;
					prevMode = mode;
				}

				mode = values[i];
				currentModeCounter = 1;
			}
		}
		if (prevModeCounter == currentModeCounter)
		{
			int realMode = Math.max(mode, prevMode);
			System.out.println(realMode);
		}
		
		else
		{
			int realModeCount = Math.max(prevModeCounter, currentModeCounter);
			int realMode = 0;
			
			if (realModeCount == prevModeCounter)
			{
				realMode = prevMode;
			}
			else
			{
				realMode = mode;
			}

			System.out.println(realMode);
		}
	}
	
	static boolean isUnique(int[] array)
	{
		boolean uniqueness = true;
		for (int i = 1; i < array.length; i++)
		{
			if (array[i] == array[i-1])
			{
				uniqueness = false;
				break;
			}
		}
		
		return uniqueness;
	}
}