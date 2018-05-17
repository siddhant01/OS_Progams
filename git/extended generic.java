//create a generic class that contains a method that returns the average of an array
// of numbers of any type, including integers, floats, and double

//maam's solutions
class GenDemo<T extends Number>   //note after this T can have only data types as Number class or its subclasses i.e Integer, Double, Byte,ect
{
	T []nums;
	GenDemo (T o[])
	{
		nums=o;
	}
	double average()
	{
		double sum=0.0;
		for(int i=0;i<nums.length;i++)
			sum+=nums[i].doubleValue();//sum+=a[i] is worng as no auto unboxing in case of generic class so you need to use the inbuilt funtion for converting to number
		return sum/nums.length;
	}
}
class Demo
{
	public static void main(String ar[])
	{
		Integer []i={1,2,3,4};
		GenDemo<Integer> g1=new GenDemo<Integer>(i);  //note i cannot have data type as int because there is no auto boxing for array of no.
		Double []d={1.3,2.6,3.2,4.9};
		GenDemo<Double> g2=new GenDemo<Double>(d);
		System.out.println(g1.average());
		System.out.println(g2.average());
	}
}

//my solution
class Gen<T extends Number>
{
	double average(T a[])
	{
		double sum=0;
		for(int i=0;i<a.length;i++)
			sum+=a[i].doubleValue();
		return sum/a.length;
	}
}
class TestGen1
{
	public static void main(String ar[])
	{
		Gen<Integer> g2=new Gen<Integer>();
		Integer a[]={1,2,3,4,5};
		System.out.println(g2.average(a));
	}
}