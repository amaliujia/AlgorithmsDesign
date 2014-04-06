public class Solution {
	public static void main(String[] args)
	{ 
		System.out.println(StringPermution(new String("aede"), new String("edac")));
	}
	public static boolean StringPermution(String s, String t)
	{	
		if(s.length() != t.length())
		{
			return false;
		}
		return sort(s).equals(sort(t));
	}
	public static String sort(String s)
	{
		char []content = s.toCharArray();
		java.util.Arrays.sort(content);
		return new String(content);
	}
	
}
