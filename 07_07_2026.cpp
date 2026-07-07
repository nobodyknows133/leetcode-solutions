class Solution {
public:
    long long sumAndMultiply(int n) {
        long long res = 0;
        long long s = 0;
        for(auto &x: to_string(n)){
            if(x!='0'){
                int d = x - '0';
                res = res*10+d;
                s+=d;
            }
        }
        return res*s; 
    }
};
