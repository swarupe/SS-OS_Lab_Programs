import java.util.Scanner;
import java.io.DataInputStream;
public class Bankers {
	public int proc_id[]= new int [10];
	public int avail[]=new int[10];
	public int n, no_res;
	public int max[][]=new int[10][10];
	public int allot[][]=new int[10][10];
	public int need[][]=new int[10][10];

	public Bankers(int n, int res)
	{
		this.n=n;
		no_res=res;
	}
	public void read_data()
	{
		int i,j;
		for(i=0;i<n;i++){
			proc_id[i]=i;
		}
		Scanner in=new Scanner(System.in);
		System.out.println("Enter available data");
		for(i=0;i<no_res;i++)
			avail[i]=in.nextInt();
		System.out.println("n="+n);
		System.out.println("Enter max matrix");
		for(i=0;i<n;i++)
			for(j=0;j<no_res;j++)
				max[i][j]=in.nextInt();
		System.out.println("Enter allot matrix");
		for(i=0;i<n;i++)
			for(j=0;j<no_res;j++)
				allot[i][j]=in.nextInt();
		for(i=0;i<n;i++)
			for(j=0;j<no_res;j++)
				need[i][j]=max[i][j]-allot[i][j];
	}

	public void print_data()
	{
		int i,j;
		System.out.println("Need  ");
		System.out.println("-------------------------");
		for(i=0;i<n;i++)
		{
			for(j=0;j<no_res;j++)
				System.out.print(need[i][j]+"   ");
			System.out.println();
		}
	}
	public void safety()
	{
		int i,j,p,k;
		System.out.println("inside safety function");
		boolean fin[]=new boolean[n+1];
		int safeSeq[]=new int[n+1];
		int work[]=new int[no_res];
		System.out.flush();
		for(i=0;i<no_res;i++)
			work[i]=avail[i];
		for(i=0;i<n;i++)
			fin[i]=false;
		int count = 0;
		while (count <n)
		{
			boolean found = false;
			for (p = 0; p < n; p++)
			{
				if (fin[p] ==false)
				{
					for (j = 0; j < no_res; j++)
						if (need[p][j] > work[j])
							break;
					if (j == no_res)
					{
						for ( k = 0 ; k < no_res ; k++)
							work[k] += allot[p][k];
						safeSeq[count++] = p;
						fin[p] = true;
						found = true;
					}
				}
			}
			if (found == false)
			{
				System.out.println("System is not in safe state");
				return;
			}
		}
		System.out.println("System is in safe state.\nSafe sequence is: ");
		for ( i = 0; i < n ; i++)
			System.out.print( safeSeq[i]+ " " );
	}
}
