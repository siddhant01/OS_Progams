class Out
{
	static int o=20;  //static var of Outter class
	int o1=30;        //non static var of Outter class
	
	static class In  
	{
		static int x=10; //static member of static inner class, not possible in member class
		int y=40;
		void meth()		//non static member of static inner class
		{
			System.out.println(o);  //to acess static memeber of outter class we don't need object.
			System.out.println(Out.o);
			System.out.println(y);
			
			//System.out.println(o1); //wrong as we are trying to acess non static directly in static class
			Out ob1=new Out();     
			System.out.println(ob1.o1);  //to acess non static memeber of outter we require obj of outter class
		}
	}

	void meth()
	{
		System.out.println(In.x);  //note you can acess the static inner static variables directly
	}
}

class Test
{
	public static void main(String ar[])
	{
		Out obj=new Out();
		obj.meth();
		
		Out.In ob=new Out.In();
		System.out.println(Out.In.x); 
		ob.meth(); 					//we need obj for accessing non static member of static inner class
	}
}