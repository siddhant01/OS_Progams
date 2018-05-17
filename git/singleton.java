//singleton =having only one instance, and if we reopen then same instance is returned

class Test
{
	private static Test obj;
	private Test()
	{
	}
	
	public static Test getInstance()
	{
		if(obj==null)  //note null not NULL
		{
			obj=new Test();
		}
		return obj;
	}
}

class SingleT
{
	public static void main(String arg[])
	{
		//Test t3=new Test();  //it gives error  thanks to private constuctor which can not be called from outside
		Test t1=Test.getInstance();
		Test t2=Test.getInstance();
		if(t1==t2)
			System.out.println("same");
	}
}