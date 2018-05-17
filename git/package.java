//1st package
//2nd import
//3rd class or interface or abstract
package InnerDemo;    //to compile every one in a package into dir we use >>javac -d . Test.java   or  javac Test.java -d .
									//and to run we use >>java InnerDemo.Test

class Out
{
	void meth()  
	{   //note method local class is local to that method
		class In       //note the output file is Out$1In.class
		{
			int x=20;
		}
		In ob=new In();
		System.out.println(ob.x);
	}
	void meth2()
	{
		class In       //note the output file is Out$2In.class
		{
			int x=20;
		}
		In ob=new In();
		System.out.println(ob.x);
	}
	void meth3()
	{
		class In2       //note the output file is Out$1In2.class
		{
			int x=20;
		}
		In2 ob=new In2();
		System.out.println(ob.x);
	}
}
class Test
{
	public static void main(String ar[])
	{
		Out o=new Out();
		o.meth();
	}
}