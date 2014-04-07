class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
            vector<int> out_res;
            vector<int> in_vec;
            for(int i=0;i<numbers.size();i++)
                in_vec.push_back(numbers[i]);
            std::sort(in_vec.begin(),in_vec.end());
            int i=0,j=(int)in_vec.size()-1;
            while(i<j){
                int sum = in_vec[i]+in_vec[j];
                if(sum>target){
                    j--;
                } else if(sum<target) {
                    i++;
                }else {
                    out_res.clear();
                    out_res.push_back(in_vec[i]);
                    out_res.push_back(in_vec[j]);
                    int index1=0,index2=0;
                    for(int i=0;i<numbers.size();i++)
                    {
                        if(numbers[i]==out_res[0])
                        {
                            index1=i+1;
                            break;
                        }
                    }
                    for(int i=0;i<numbers.size();i++)
                    {
                        if((numbers[i]==out_res[1])&&(i!=index1-1)){
                            index2=i+1;
                            break;
                        }
                    }
                    out_res.clear();
                    if(index1<index2){
                        out_res.push_back(index1);
                        out_res.push_back(index2);
                    }else {
                        out_res.push_back(index2);
                        out_res.push_back(index1);
                    }
                    return out_res;
                }
               
            } 
    }
};

