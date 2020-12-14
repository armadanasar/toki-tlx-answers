import java.util.Scanner;

public class CompositeFunction 
{
	int A = 0;
	int B = 0;
	
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		CompositeFunction cf = new CompositeFunction();
		
		cf.A = sc.nextInt();
		cf.B = sc.nextInt();
		//Untuk membantu debugging saja (jadi bisa saya lihat di variables)
		/*int helpA = cf.A;
		int helpB = cf.B;*/
		int iterations = sc.nextInt();
		int x = sc.nextInt();
		sc.close();
		//int result = 0;
		for (int i = 1; i <= iterations; i++)
		{
			x = cf.f(x);
		}
		if (iterations > 0)
			System.out.println(x);
		else
			System.out.println(0);
	}
	
	int f(int x)
	{
		return Math.abs((A * x) + B);
	}
}