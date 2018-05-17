class Sup
{
	void meth()
	{
		System.out.println("super class meth");
	}
}
class Sub extends Sup
{
}
class Test
{
	public static void main(String arg[])
	{
		Sub sb=new Sub();
		sb.meth();
	}
}