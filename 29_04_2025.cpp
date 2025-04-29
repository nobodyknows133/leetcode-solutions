class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(begin(nums),end(nums));
        int n = nums.size();
        int l = 0;
        int r = 0;
        long long res = 0l;
        int cnt = 0;
        while(r<n){
            if(nums[r]==mx){
                cnt+=1;
            }
            while(cnt>=k){
                res+=(n-r);

                if(nums[l]==mx) {
                    cnt-=1;
                }
                l++;
            }
            r++;
        }

        return res;
        
    }
};
