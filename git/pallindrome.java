/* wap to check if a given string is palindrome or not. take string input through command line arguments*/
class Test1
{
	public static void main (String arg[])
	{
		StringBuilder sb1=new StringBuilder(arg[0]);
		sb1.reverse();
		if(arg[0].equals(sb1.toString()))
			System.out.println("palindrome");
		else
			System.out.println("not palindrome");
	}
}
class Test2
{
	public static void main(String arg[])
	{
		StringBuilder sb1=new StringBuilder("test class");
		StringBuilder sb2=new StringBuilder("test class");
		
		sb1.delete(2,6);
		sb2.deleteCharAt(1);
		
		System.out.println(sb1);
		System.out.println(sb2);
	}
}

class Test3
{
	public static void main(String arg[])
	{
		StringBuilder sb=new StringBuilder("this is demo");
		String s="XXXXXX";
		sb.replace(2,4,s);
		System.out.println(sb);
	}
}