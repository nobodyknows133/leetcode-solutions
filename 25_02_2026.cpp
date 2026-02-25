class Solution {
public:
    static bool f(int a,int b){
        auto x = __builtin_popcount(a);
        auto y = __builtin_popcount(b);
        if(x!=y){
            return x<y;
        }
        else{
            return a<=b;
        }
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr),end(arr),f);
        return arr;
    }
};
