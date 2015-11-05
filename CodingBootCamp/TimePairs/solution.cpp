void findAllTimePairs(queue<float> time, queue<float> time2){
  vector<float> q1, q2;

  q1.push_back(time.front());
  q2.push_back(time2.front());
  time.pop();
  time2.pop();
  if(abs(q1[0] - q2[0]) < 1){
    cout << q1[0] << " " << q2[0] << endl;
  }
  
  while(!time.empty() && !time2.empty()){
    float t1 = time.front();
    float t2 = time2.front();
    time.pop();
    time2.pop();

    int index = 0;
    while(!q1.empty() && index < q1.size()){
       if(abs(q1[index]- t1) < 1){
          count << q1[0] << " " << t1 << endl;
          index++;
       }else if(q1[index] < t1){
          q1.erase(q1.begin()+index); 
       }else{
          break;
       } 
    }

    index = 0;
    while(!q2.empty() && index < q2.size()){
       if(abs(q2[index]- t2) < 1){
          cout << q2[0] << " " << t2 << endl;
          index++;
       }else if(q2[index] < t2){
          q2.erase(q2.begin()+index); 
       }else{
          break;
       } 
    }
    q1.push_back(t1);
    q2.push_back(t2);
  } 
} 
