/*
	s1 = xy
	s2 = yx
	therefore s2 must be the substirng of s1s1(xyxy)
*/

boolean RotationString(String s, String target)
{
	String container = s + s;
	if(s.length() != target.length()){
		return false;
	}
	if(isSubstirng(container, target){
		return true;
	}
	return false;
}
