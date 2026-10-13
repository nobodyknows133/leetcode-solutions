class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> tmp;
        for(auto x: nums){
            tmp.push_back(1l*x*x);
        }
        sort(tmp.begin(),tmp.end());
        int n = tmp.size();
        long long res = 0;
        long long a = 0;
        long long b = 0;
        for(int i=0;i<n/2;i++){
            b+=tmp[i];
        }

        for(int i=n/2;i<n;i++){
            a+=tmp[i];
        }
        return a-b;
    }
};
