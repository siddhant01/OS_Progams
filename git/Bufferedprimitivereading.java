import java.io.*;   //note use java.io.*;  for Streams
class Demo throws
{
	public static void main(String ar[]) throws Exception  //throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		String s=br.readLine();
		System.out.println(s);
	}
}