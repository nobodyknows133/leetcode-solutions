class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;

        for(auto x: nums){
            string y = to_string(x);
            if(y.size()%2==0){
                res++;
            }
        }

        return res;
        
    }
};
