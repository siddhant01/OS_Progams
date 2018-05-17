class Test
{
	public static void main(String ar[])
	{
		int x=80,y=0;
		int a[]={1,2,3,4};
		try
		{
			a[5]=90;
			int z=x/y;  //this will not run as 1st interrutpion will disrrupt the program flow
		}
		catch(ArrayIndexOutOfBoundsException e) 
		{
			System.out.println("check the array index number");
			System.out.println("at index: "+e.getMessage()); 
		}
	}
}