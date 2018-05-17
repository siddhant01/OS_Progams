class Test
{
	public static void main(String a[])
	{
		String s1="this is an issueless issue";
		String s2=s1.replace('s','S');
		System.out.println(s2);
		String s3="    Test   class    ";
		String s4=s3.trim();
		
		System.out.println(s3.length());
		System.out.println(s4.length());
		
		String s5=s1.substring(3,9);
		System.out.println(s5);
	}
}