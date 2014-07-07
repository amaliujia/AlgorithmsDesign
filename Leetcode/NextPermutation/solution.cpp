// O(n) time
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i, j;
        for(i = num.size() - 2; i >= 0; i--){
            if(num[i] < num[i + 1]){
                break;
            }
        }
        if(i >= 0){
            for(j = num.size() - 1; j > i; j--){
                if(num[i] < num[j]){
                    swap(num[i], num[j]);
                    break;
                }
            }
        }
        for(j = num.size() - 1, i = i + 1; i <= j; i++, j--){
            int temp = num[j];
            num[j] = num[i];
            num[i] = temp;
        } 
    }
};
