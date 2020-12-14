import java.util.Scanner;

class NotImplementedYetException extends Exception
{
	private static final long serialVersionUID = 3743700699912319215L;	
}

public class TukangSulap 
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		
		int numberOfBallsPerRow = sc.nextInt();
		int[] rowABalls = new int[numberOfBallsPerRow];
		int[] rowBBalls = new int[numberOfBallsPerRow];
		
		for (int i = 0; i < numberOfBallsPerRow; i++)
			rowABalls[i] = sc.nextInt();
		for (int i = 0; i < numberOfBallsPerRow; i++)
			rowBBalls[i] = sc.nextInt();
		
		int numberOfSwaps = sc.nextInt();
		String[] commands = new String[numberOfSwaps];
		sc.nextLine();
		for (int i = 0; i < numberOfSwaps; i++)
			commands[i] = sc.nextLine();
		
		sc.close();
		
		//IO Verification Code!
		/*System.out.println(numberOfBallsPerRow  + "");
		
		for (int i = 0; i < numberOfBallsPerRow; i++)
			System.out.print(rowABalls[i] + " ");
		System.out.println("");
		
		for (int i = 0; i < numberOfBallsPerRow; i++)
			System.out.print(rowBBalls[i] + " ");
		System.out.println("");
		
		System.out.println(numberOfSwaps);
		
		for (int i = 0; i < numberOfSwaps; i++)
			System.out.println(commands[i] + "");*/
	
		String[] commandCache = new String[4];
		for (int i = 0; i < numberOfSwaps; i++)
		{
			commandCache = commands[i].split(" ");
			String posOne = commandCache[0];
			int posOneBallNumber = Integer.parseInt(commandCache[1]);
			String posTwo = commandCache[2];
			int posTwoBallNumber = Integer.parseInt(commandCache[3]);
			
			//Parser verification code
			/*System.out.println("Command #" + (i + 1));
			System.out.print("posOne: " + posOne + "; ");
			System.out.print("posOneBallNumber: " + posOneBallNumber + "; ");
			System.out.print("posTwo: " + posTwo + "; ");
			System.out.print("posOneBallNumber: " + posTwoBallNumber);
			System.out.println("");*/
			try
			{
				swap(rowABalls, rowBBalls, posOne, posOneBallNumber, posTwo, posTwoBallNumber);
			} catch(NotImplementedYetException ex) {
				
			}
		}
		
		for (int j = 0; j < numberOfBallsPerRow; j++)
		{
			if (j == numberOfBallsPerRow-1)
				System.out.println(rowABalls[j]);
			else
				System.out.print(rowABalls[j] + " ");
		}
		//System.out.println("");
		for (int j = 0; j < numberOfBallsPerRow; j++)
		{
			if (j == numberOfBallsPerRow-1)
				System.out.println(rowBBalls[j]);
			else
				System.out.print(rowBBalls[j] + " ");
		}
		//System.out.println("");
		
		/*addOne(rowABalls);
		for (int i = 0; i < numberOfBallsPerRow; i++)
			System.out.print(rowABalls[i] + " ");*/
	}
	
	static void addOne(int[] input)
	{
		for (int i = 0; i < input.length; i++)
			input[i] += 1;
	}
	
	static void swap(int[] RowABalls, int[] RowBBalls, String posOne, int posOneBallNumber, String posTwo, int posTwoBallNumber) throws NotImplementedYetException
	{
		int realPosOneBallIndex = posOneBallNumber - 1;
		int realPosTwoBallIndex = posTwoBallNumber - 1;
		
		int temp = 0;
		
		if (posOne.equals("A") && posTwo.equals("B"))
		{
			temp = RowABalls[realPosOneBallIndex];
			RowABalls[realPosOneBallIndex] = RowBBalls[realPosTwoBallIndex];
			RowBBalls[realPosTwoBallIndex] = temp;
		}
		
		if (posOne.equals("B") && posTwo.equals("A"))
		{
			temp = RowBBalls[realPosOneBallIndex];
			RowBBalls[realPosOneBallIndex] = RowABalls[realPosTwoBallIndex];
			RowABalls[realPosTwoBallIndex] = temp;
		}
		
		if (posOne.equals("A") && posTwo.equals("A"))
		{
			temp = RowABalls[realPosOneBallIndex];
			RowABalls[realPosOneBallIndex] = RowABalls[realPosTwoBallIndex];
			RowABalls[realPosTwoBallIndex] = temp;
		}
		
		if (posOne.equals("B") && posTwo.equals("B"))
		{
			temp = RowBBalls[realPosOneBallIndex];
			RowBBalls[realPosOneBallIndex] = RowBBalls[realPosTwoBallIndex];
			RowBBalls[realPosTwoBallIndex] = temp;
		}
	}
}