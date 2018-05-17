class Test
{
	public static void main(String arr[])
	{
		String s1="abde";
		String s2="afgr";
		System.out.println(s1.compareTo(s2));
		
		String s3="This is a test issue";
		String s4="is";
		char c='t';
		
		System.out.println(s3.indexOf(s4));
		System.out.println(s3.indexOf(c));
		System.out.println(s3.lastIndexOf(s4));
		System.out.println(s3.lastIndexOf(c));
		System.out.println(s3.indexOf(s4,4));
		System.out.println(s3.indexOf(c,11));
	}
}

/* wap to count the number of occurance of "is" in "this is an issueless issue"*/
//not done
class WAP
{
	public static void main(String ar[])
	{
		//my method
		String s="this is an issueless issue";
		String c="is";
		int co=0;
		int i=0;
		int temp=0;
		do
		{
			temp=s.indexOf(c,i);
			if(temp>0)
			{
				co++;
				i=temp+1;
			}
			else
				break;
		}while(true);
		System.out.println(co);
		
		
		System.out.println();
		
		//ma'am's method
		String s1="this is an issueless issue";
		String s2="is";
		int count=0;
		i=-1;
		while((i=s1.indexOf(s2,i+1))>=0)
			count++;
		
		System.out.println(count);
	}
}