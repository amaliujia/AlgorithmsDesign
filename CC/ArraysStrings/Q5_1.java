/*
	Time complexity is O(P + n^2)
	P is the length of String s(we iterate through it)
	n is the times of string concatenation. n^2 is the cost of concatenation
	Thus the final time complexity should be O(n^2)
*/

public String zipSpaces(String s)
{
	String newS = "";
	int count = 1;
	char current = s.charAt(0);
	for(int i = 1; i < s.length(); i++)
	{
		if(current == s.charAt[i])
		{
			count++;
		}else{
			newS += current + "" + count;
			current = s.charAt[i];
			count = 1;
		}
	}
	return newS + current + "" + count;	
}
