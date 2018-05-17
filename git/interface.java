interface A
{
	void meth1();
	void meth2();
}

class Test implements A
{
	public void meth1()   //note by default the access specifier of interface methods are public and varibles are public static & final
	{
		System.out.println("meth1");
	}
	
	pulic void meth2()   //note if we use void meth2() only then error
	{
		System.out.println("meth2");
	}
	
	public static void main(String ar[])
	{
	}
}