class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ss = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int l = 0;
        int r = 0;
        int res = -1;
        int s = 0;
        while(r<n){
            s+=nums[r];
            while(l<=r && s>ss-x){
                s-=nums[l];
                l++;
            }
            if(s==ss-x){
                res = max(res,r-l+1);
            }
            r++;
        }

        return res == -1? -1 : n-res;
    }
};
