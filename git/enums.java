class EnumExample1
{
	enum Season 
	{ 
		Winter, Sprint, Summer, Fail
	} 		//note there are not strings+
			//note no ';'

	public static void main(String arg[])
	{
		for(Season a:Season.values())
			System.out.println(a);
		
		Season aa[]=Season.values();
		for(int i=0; i<aa.length; i++)
			System.out.println(aa[i]);
	}
}

