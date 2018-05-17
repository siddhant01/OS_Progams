/*Given a stirng array containing the name of all the student in the class.
Write a program to find the names of all the students whose last name is "Singh";
*/
class NameMatch
{
	public static void main(String arr[])
	{
		String s[]={"Siddhant Sauarbh","Kartik Mahajan","Aman Dubey","Abhay Singh"};
		String c="Singh";
		for(int i=0;i<s.length;i++)
		{
			if(c.regionMatches(0,s[i],s[i].length()-c.length(),c.length()))
				System.out.println(s[i]);
		}
		
		System.out.println();
		
		
		for(int i=0;i<s.length;i++)
		{
			if(s[i].endsWith("Singh"))
				System.out.println(s[i]);
			
			if(s[i].toLowerCase().endsWith(c.toLowerCase()))
				System.out.println(s[i]);
		}
	}
}