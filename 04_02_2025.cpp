class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        long long res = nums[0];
        long long s = nums[0];
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i==0) continue;
            if(nums[i]>nums[i-1]){
                s+=nums[i];
            }
            else{
                res = max(res, s);
                s=nums[i];
            }
        }

        res = max(res, s);

        return res;
        
    }
};
