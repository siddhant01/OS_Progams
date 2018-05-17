class Test  //don't use predefined classe's names like Exception
{
	public static void main(String ar[]) throws Exception// for passing exception to the parent,
	{
		int x=80,y=0;
		int a[]={1,2,3,4};
		//try with finally
		try
		{
			System.out.println("i will execute"); //it will run
			a[2]=90;
			int z=x/y;
			System.out.println("i won't execute");
		}
		finally
		{
			System.out.println("good bye");
		}
		System.out.println("hello");
	}
}