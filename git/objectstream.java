import java.io.*;

class A implements Serializable   //note for writing an object of a class, then that class must implements Serializable interface
{
	int x=10;
	transient int y=20;  //will not be written to the file
}

class Test
{
	public static void main(String ar[]) throws IOException, ClassNotFoundException //or throws Exception note these are check exceptions
	{
		A ob=new A();
		
		FileOutputStream fo =new FileOutputStream("abc.txt");
		ObjectOutputStream oo =new ObjectOutputStream(fo);
		
		oo.writeObject(ob);
		
		FileInputStream fi =new FileInputStream("abc.txt");
		ObjectInputStream oi=new ObjectInputStream(fi);
		
		A o=(A)oi.readObject();               //note readObject() return object of type Object Class so they need to be type casted to specific class before using them
		
		System.out.println(o.x+"    "+o.y);
		oi.close();
		oo.close();
		fo.close();
		fi.close();
	}
}
/*
Write a program that stores an object containing an array of 5 int values 1,2,3,4, and 5,
a double values 4.5 and a String "hello" into a file named Questions.txt, futher read the contents of
the file and diplay the values on the console. What will be the output if the double variable is
declared as transient?  0.0
*/

class B implements Serializable
{
	int[] x={1,2,3,4,5};
	String s="hello";
	transient double y=4.5;   //default value of double is 0.0
}

class Test2
{
	public static void main(String ar[]) throws IOException, ClassNotFoundException //or throws Exception
	{
		B ob=new B();
		
		FileOutputStream fo =new FileOutputStream("Queston.txt");  //note Question.txt comes to be a binary file
		ObjectOutputStream oo =new ObjectOutputStream(fo);
		
		oo.writeObject(ob);
		
		FileInputStream fi =new FileInputStream("abc.txt");
		ObjectInputStream oi=new ObjectInputStream(fi);
		
		B o=(B)oi.readObject();
		
		System.out.println(o.x[1]+"    "+o.y+"   "+o.s);
		
		fo.close();
		fi.close();
		oi.close();
		oo.close();
	}
}
