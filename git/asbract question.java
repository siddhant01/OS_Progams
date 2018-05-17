abstract class Demo
{
	Demo()
	{
		print();
	}
	abstract void print(); 
}

class Main extends Demo
{
	int y;
	Main()
	{	
		y=90;
	}
	
	void print()
	{
		System.out.println(y);
	}
	
	public static void main( String ar[])
	{
		Main m=new Main();
	}
}
//output 0