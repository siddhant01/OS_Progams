class Sup
{
	int x=10;
	void meth()
	{
		System.out.println("super class meth");
	}
}
class Sub extends Sup
{
	int y=20;
	void meth1()
	{
		System.out.println("sub class meth");
	}
}

class Test
{
	public static void main(String arg[])
	{
		//object slicing
		Sup su=new Sub();
		
		su.meth();					//of parent
		System.out.println(su.x);  //of parent
	}
}
