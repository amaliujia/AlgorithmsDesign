// O(n)

int findMedian(vector<int> target){
	if(target.size() <= 5){
		sort(target.begin(), target.end);
		int index = target.size() / 2;
		int judge = target.size() % 2;
		if( judge == 0){
			return (target[index - 1] + target[index]) / 2;	
		}else{
			return target[index];
		}	
	}

	vector<int> medians;
	int dis = 5;
	int start = 0;
	
	while(target.size() > dis){
	   vector<int> temp;
	   if(target.size() - dis >= 5){
	  		 for(int i = start; i < start + 5; i++){
				temp.push_back(target[i]);	
	   	   	 }
			 sort(temp.begin(), temp.end());
			 medians.push_back(temp[2]);
		}else{
			for(int i = start; i < start + (target.size() - dis); i++){
				temp.push_back(target[i]);
			}
			sort(temp.begin(), temp.end());
			int index = temp.size() / 2;
        	int judge = temp.size() % 2;	
			if( judge == 0)
        		medians.push_back(target[index - 1] + target[index] / 2);
			else
				medians.push_back(target);
		}
		dis += 5;
		start += 5;		
	}
	return findMedian(median);	
}
