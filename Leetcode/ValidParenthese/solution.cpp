class Solution{
public:
	bool isValid(string const& s){
		string left = "([{";
		string right = ")]}";
		stack<char> s;

		for(char c : s){
			if(left.find(c) != -1){
				s.push(c);
			}else{
				if(s.empty() || s.top() != left[right.find(c)]){
					return false;
				}else{
					s.pop();
				}
			}
		}
	    if(!sta.empty()) return false;
        return true;
	}
};
