import java.util.Scanner;

class InsufficientItemsException extends Exception
{
	static final long serialVersionUID = 0;
}

public class PolaI 
{
	public static void main(String[] args) throws InsufficientItemsException
	{
		Scanner in = new Scanner(System.in);
		String buf = in.nextLine();
		in.close();
		
		String[] bufArray = new String[2];
		bufArray = buf.split(" ");
		if (bufArray.length != 2)
			throw new InsufficientItemsException();
		in = null;
		int value = Integer.parseInt(bufArray[0]);
		int restrictor = Integer.parseInt(bufArray[1]);
		int i = 1;
		
		while (i <= value)
		{
			if (i % restrictor == 0)
				System.out.print("*");
			else
				System.out.print(i);
			if (i < value)
				System.out.print(" ");
			i++;
		}
		System.out.println("");
		
		//System.out.println(buf);
	}
}