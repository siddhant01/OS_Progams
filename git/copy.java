/*
Write a class "Copy" to simulate the cp command.
The program must copy the contents of one file to another, where the file names are entered by the user at runtime.
>>java Copy abc.txt abc1.txt;
*/
import java.io.*;
class Copy
{
	public static void main(String ar[]) throws IOException
	{
		FileInputStream fi=new FileInputStream(ar[0]);	//note ar[0] is type casted into file object
		FileOutputStream fo=new FileOutputStream(ar[1]); 
		
		int ch=fi.read();		
		while(ch!=-1)         
		{
			fo.write((char)ch);
			ch=fi.read();       
		}

		
		
		fo.close();
		fi.close();
	}
}
/*
Write a class "Copy" to simulate the cp command.
The program must copy the contents of two file to another, where the file names are entered by the user at runtime.
>>java Copy abc.txt abc1.txt abc2.txt 
*/
class Copy2
{
	public static void main(String ar[]) throws IOException
	{
		FileInputStream fi1=new FileInputStream(ar[0]);
		FileInputStream fi2=new FileInputStream(ar[1]);
		FileOutputStream fo=new FileOutputStream(ar[2]);
		
		int ch=fi1.read();
		while(ch>0)
		{
			fo.write((char)ch);
			ch=fi1.read();       
		}
		
		ch=fi2.read();
		while(ch>0)
		{
			fo.write((char)ch);
			ch=fi2.read();       
		}
		
		fo.close();
		fi1.close();
		fi2.close();
		
	}
}