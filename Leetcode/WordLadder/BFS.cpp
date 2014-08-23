// O(n^m) time, n is the length of start and end, m is the number of elements in dictionary

int ladderLength(string start, string end, unordered_set<string> &dict){
	if(start.size() != end.size())	return 0;
	if(start.empty() || start.empty())	return 0;
	if(dict.size() == 0)	return 0;
	
	int distance = 1;
	queue<string> queToPush, queToPop;
	queToPop.push(start);

	while(dict.size() && !queToPop.empty()){
		while(!queToPop.empty()){
			string str(queToPop.front());
			queToPop.pop();
			for(int i = 0; i < str.size(); i++){
				for(char j = 'a'; j < 'z'; j++){
					if(j == str[i])	continue;
					char c = str[i];
					str[i] = j;
					if(str == end)	return distance + 1;
					if(dict.count(str) > 0){
						queToPush.push(str);
						dict.erase(str);
					}
					str[i] = c;
				}
			}
		}	
		swap(queToPush, queToPop);	
		distance++;	
	}
	return 0;
}
