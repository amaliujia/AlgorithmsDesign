// O(logn) time
// O(logn) space

class Solution {
public:
    double pow(double x, int n) {
        if(n >= 0)
            return power(x, n);
        else
            return 1 / power(x, -n);
    }

private:
    double power(double x, int n){
        if(n == 0)  return 1;
        if(n == 1)  return x;
        double d = power(x, n / 2);
        if(n % 2 == 0)  return d * d;
        else    return d * d * x;
    }
};
