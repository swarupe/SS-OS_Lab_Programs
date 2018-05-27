import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.InputStreamReader;
import java.util.Scanner;
public  class pgm
{
	public  static void main(String  args[])
	{
		int  n,res; 
		Bankers bn;
		Scanner in=new Scanner(System.in);
		System.out.println("Enter the number of processes:");
		n=in.nextInt();
		System.out.println("Enter the number of resources:");
		res=in.nextInt();
		bn=new Bankers(n,res);
		bn.read_data();
		bn.print_data();
		bn.safety();
 	}
}
