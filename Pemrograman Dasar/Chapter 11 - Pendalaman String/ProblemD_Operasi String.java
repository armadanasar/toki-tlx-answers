import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String a = "";
		String b = "";
		String c = "";
		String d = "";
		
		a = sc.nextLine();
		b = sc.nextLine();
		c = sc.nextLine();
		d = sc.nextLine();
		
		a = a.replaceAll(b, "");
		a = a.replaceAll(c, (c+d));

		System.out.println(a);
	}
}