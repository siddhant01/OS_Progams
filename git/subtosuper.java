class Sup
{
	int x=10;
	void meth()
	{
		System.out.println("super class meth");
	}
	void meth1()
	{
		System.out.println("supper meth1");
	}
}
class Sub extends Sup
{
	int x=20;
	void meth()
	{
		System.out.println("sub class meth");
	}
	void meth2()
	{
		System.out.println("sub meth2");
	}
}

class Test
{
	public static void main(String arg[])
	{
		Sup su=new Sub();
							
		su.meth();					//of child
		System.out.println(su.x);  //of parent
		su.meth1();
		//su.meth2();    error 
	}
}
