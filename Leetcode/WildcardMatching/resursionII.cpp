// lowercase character  [a-z]
// ?  match any single character
// * match zero or more character
//
// *******   a   true\
//
// 2^n
bool matching(string pattern, string target){
  if(pattern.length() == 0){
    return target.length() == 0;
   }else if(pattern[0] == '*'){
      return matching(pattern[1:], target) || matching(pattern, target[1:]); 
   }else{
    return (target.length() != 0) && (pattern[0] == target[0] || pattern[0] == "?") && mathcing(pattern[1:], t[1:]); 
   }
}
