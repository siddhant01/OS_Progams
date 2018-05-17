
class Rect
{
	int l, b;
	Rect(int l , int b)
	{
		this.l = l;
		this.b = b;
	}
	int area()
	{
		return l*b;
	}
	int peri()
	{
		return 2*(l+b);
	}
}
class RectComparatorPeri implements Comparator<Rect>
{
	public int compare(Rect r1 , Rect r2)
	{
		if(r1.peri() < r2.peri())
			return 1;
		else if(r1.peri() < r2.peri())
			return -1;
		else
			return 0;
	}
}
class Test{
	public static void main(String args[])
	{
	  TreeSet<Rect> t1 = new TreeSet<Rect>(new RectComparatorPeri());
	  t1.add(new Rect(4,5));
	  t1.add(new Rect(2,5));
	  t1.add(new Rect(4,3));
	  t1.add(new Rect(4,1));
	  
	  Iterator  i = t1.iterator();
	  while(i.hasNext())
	  {
	  	System.out.println(((Rect)i.next()).peri());
	  }
	  TreeSet<Rect> t2 = new TreeSet<Rect>(new RectComparatorArea());
	  t2.add(new Rect(4,5));
	  t2.add(new Rect(2,5));
	  t2.add(new Rect(4,3));
	  t2.add(new Rect(4,1));
	  
	  Iterator i1 = t2.iterator();
	  while(i1.hasNext())
	  {
	  	System.out.println((Rect)i1.next()).area());
	  }
	}
}

//  Assertions ( part of exceptions )

class AssertTest{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int age sc.nextInt();
		
		assert age >18 : "not approved";
		System.out.println("welcome voter");
	}
}
//javac lec33.java
//java -ea AssertTest
