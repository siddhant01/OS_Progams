class Test
{
	public static void main(String ar[])
	{
		int x=80,y=0;
		int a[]={1,2,3,4};
		
		try
		{
			a[6]=90;
			int z=x/y;
		}
		catch(ArithmeticException e)
		{
			System.out.println("check the values");
			System.out.println(e.getMessage());
		}
		catch(Exception e)  //it is catch all, if it is above all other exception then a error( not exception) occurs
		{
			System.out.println("oops!!");
		}
		
	}
}