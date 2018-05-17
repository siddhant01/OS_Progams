//array list type casting
import java.util.*;
class Demo
{
	public static void main(String ar[]) 
	{
		ArrayList al=new ArrayList();
		
		al.add(10);
		int i =(Integer)al.get(0); //the array list store the object of Object class, so need to type cast to specific class object, note auto unboxing is used here
		System.out.println(i);
		
		al.add("hello");
		String s=(String)al.get(1);
		
		System.out.println(s);
	}
}

class Demo1
{
	public static void main(String ar[])
	{
		ArrayList<String> al=new ArrayList<String>(); 
		
		al.add("hello");
		String s=al.get(0); //no type casting is required here
		
		System.out.println(s);
		
		ArrayList<Integer> al2=new ArrayList<Integer>();
		
		al2.add(10);  
		int n=al2.get(0); //auto unboxing as Integer->int
		
		System.out.println(n);
	}
}

//nongeneric working like of array list
class NonGen
{
	Object ob;
	NonGen(Object o)
	{
		ob=o;
	}
	
	Object get()
	{
		return ob;
	}
}

class TestGen
{
	public static void main(String ar[])
	{
		NonGen g1=new NonGen("hello");
		
		String s=(String)g1.get();
		System.out.println(s);
		
		NonGen g2=new NonGen(90);
		int i=(Integer)g2.get();
		
		System.out.println(i);
	}
}
