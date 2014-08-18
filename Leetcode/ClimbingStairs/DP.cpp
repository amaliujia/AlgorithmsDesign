class Solution {
public:
    int climbStairs(int n) {
        int x = 1, y = 2;
        if(n == 1)  return 1;
        if(n == 2)  return 2;
        int i = 3;
        int result;
        while(i <= n){
           result = x + y;
           x = y;
           y = result;
           i++;
        }
        return result;
    }
};
