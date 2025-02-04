class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int l1 = 1;
        int l2 = 1;
        int mxl1 = 1;
        int mxl2 = 1;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(i==0) continue;
            if(nums[i]>nums[i-1]){
                l1++;
                mxl2 = max(mxl2, l2);
                l2=1;
            }
            else if(nums[i]<nums[i-1]) {
                l2++;
                mxl1 = max(mxl1, l1);
                l1 = 1;
            }
            else{
                mxl2 = max(mxl2, l2);
                mxl1 = max(mxl1, l1);
                l1 = 1;
                l2 = 1;
            }    
        }
        mxl1 = max(mxl1,l1);
        mxl2 = max(mxl2,l2);

        // cout<<mxl1<<" "<<mxl2;
        return max(mxl1,mxl2);
        
    }
};
