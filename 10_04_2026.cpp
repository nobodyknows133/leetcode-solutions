class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int sol = 4*n+5;

        if(n<3){
            return -1;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]==nums[j] && nums[j]==nums[k] && nums[i]==nums[k]){
                        sol = min(sol, abs(i-j) + abs(j-k) + abs(k-i));
                    }
                }
            }
        }

        return (sol==4*n+5?-1:sol);
    }
};
