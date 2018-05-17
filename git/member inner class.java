class Out
{
	int x=10;             //non static member of Out class
	static int y=20;      //static member of Out class
	
	void  methOut() 
	{
		In ob=new In();    
		ob.meth();        //to acess member of member inner class we need object of it
	}
	
	class In
	{
		//static int a=5;  //we cannot use static in non static inner class
		void meth()
		{
			System.out.println(x);    //as it is a member class so, it can acess both static as well as non staic member
			System.out.println(y);
		}
	}
}

class Test
{
	public static void main(String ar[])
	{
		Out o=new Out();
		o.methOut();
		
		Out.In i=o.new In();  
		i.meth();

	}
}