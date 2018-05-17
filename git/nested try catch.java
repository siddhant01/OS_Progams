//nested try catch
class Test
{
	public static void main(String ar[])
	{
		int x=10,y=0,a[]={1,2,3,4};
		try
		{
			a[2]=90;  //a[7]=90; outter try can't acess inner try's catch so error, but inner try can acesses outter try's catch
			try
			{
				int z=x/y;
			}
			catch(ArrayIndexOutOfBoundsException e)
			{
				System.out.println("array exception");
			}
		}
		catch(ArithmeticException e)
		{
			System.out.println("divide by 0 exception");
		}
	}
}