import java.time.*;   //note import it
class Test
{
	public static void main(String arg[])
	{
		LocalTime t=LocalTime.now();   
		LocalDate l=LocalDate.now();
		
		System.out.println(l+"   "+t);
		
		LocalTime t1=LocalTime.of(22,44,22);
		LocalDate l1=LocalDate.of(2010,Month.JANUARY,23);
		
		System.out.println(l1+"  "+t1);
		
		LocalTime t2=LocalTime.of(5,55,23,234);
		LocalDate l2=LocalDate.of(2012,6,21);
		
		System.out.println(l2+" "+t2);
		
		LocalTime t3=LocalTime.parse("11:22:14");
		LocalDate l3=LocalDate.parse("1999-09-23");
		
		System.out.println(l3+"  "+t3);
	}
}

class Test2
{
	public static void main(String arg[])
	{
		LocalDateTime ldt=LocalDateTime.now(ZoneId.of("Europe/Paris"));
		
		System.out.println(ldt);
		
	}
}