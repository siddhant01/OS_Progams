//tree set
import java.util.*;

class TestC1
{
	public static void main(String ar[])
	{
		TreeSet <String> t1 = new TreeSet <String>();  //TreeSet is Set of Best (same values are discarded)
		t1.add("test");
		t1.add("demo");
		t1.add("test");
		t1.add("value");
												
		Iterator <String> i=t1.iterator();     
		while(i.hasNext())
			System.out.println(i.next());
	}
}


// Deque
class TestC3
{
	public static void main(String ar[])
	{
		Deque<String> t1=new LinkedList<String>();   //deque linklist
		t1.addFirst("a");
		t1.offerFirst("b");
		t1.addLast("c");
		t1.offerLast("d");
		System.out.println(t1.getFirst()); 
		System.out.println(t1.peekFirst()); 
		
		
		while(t1.size()>0)
			System.out.println(t1.remove());  
	}
}

//hash map
//import java.util.*;
class TestC4
{
	public static void main(String ar[])
	{
		HashMap<Integer,String> map=new HashMap<Integer,String>();
		
		map.put(101,"let us C");
		map.put(102,"Operating System");
		map.put(103,"Data Communication and Networking");
		
		System.out.println("Values before remove: "+map);
		
		map.remove(102);
		System.out.println("Value agter remove: "+map);
		
		
		for(Map.Entry m:map.entrySet())
			System.out.println(m.getKey()+" "+m.getValue());
		
	}
}