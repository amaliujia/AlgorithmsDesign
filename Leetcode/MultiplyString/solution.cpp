// O(n^2) time
// O(n) space
	typedef vector<int> bigint;
    bigint operator*(const bigint &x, const bigint &y){
        bigint r(x.size() + y.size());
        for(int i = 0; i < x.size(); i++){
            for(int j = 0; j < y.size(); j++){
                r[i + j] += x[i] * y[j];
                r[i + j + 1] += (r[i + j] / 10);
                r[i + j] %= 10;
            }
        }
        return r;
    }

    bigint bigInt(const string &num){
        bigint n;
        transform(num.rbegin(), num.rend(), back_inserter(n),
              [](char c) {return c - '0';});
        return n;
    }
    
    string to_string(const bigint &n){
        string str;
        transform(find_if(n.rbegin(), prev(n.rend()), [](char c) { return c > '\0'; }), n.rend(), back_inserter(str), [](char c) { return c + '0'; });
        return str;
    }
    
	string multiply(string num1, string num2) {
        return to_string(bigInt(num1) * bigInt(num2));
    }
