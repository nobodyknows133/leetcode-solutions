class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;

        for(int i=1;i<n;i++){
            int n1 = nums[i];
            int n2 = nums[i-1];

            if(n1%2==n2%2){
                return false;
            }
        }

        return true;
        
    }
};
