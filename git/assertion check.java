//  Assertions ( part of exceptions )
import java.util.*;
class AssertTest
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int age= sc.nextInt();
		
		assert age >18 : "not approved";		//when this conditon is false then programm gives error and terminate
		System.out.println("welcome voter");
	}
}
//javac lec33.java
//java -ea AssertTest