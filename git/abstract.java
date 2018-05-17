abstract class Figure
{
	int d1,d2;
	Figure()
	{
		System.out.println("papa abstract classed automatically by the auto child constructor");
		d1=10;
		d2=20;
	}
	final void greet()
	{
		System.out.println("hello");
	}
	abstract void area();
}
class Rect extends Figure
{
	void area()
	{
		System.out.println(d1*d2);
	}
}
class Test
{
	public static void main(String arg[])
	{
		Rect r=new Rect();
		r.area();
		//Figure f=new Figure(); //error as abstract cannot have object
		r.greet();
	}
}
