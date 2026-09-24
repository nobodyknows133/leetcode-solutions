class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            string y = to_string(nums[i]);
            int res = 0;
            for(char ch: y){
                res+=(ch-'0');
            }
            if(res==i){
                return i;
            }
        }
        return -1;
    }
};
