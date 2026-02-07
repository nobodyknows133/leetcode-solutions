class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> dp(n,1);
        int mxA = 0;
        int mxB = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                dp[i]=max(mxA + 1,dp[i]);
                mxA = dp[i];
            }
            else{
                dp[i]=max(dp[i],max(mxA+1,mxB+1));
                mxB = dp[i];
            }
        }
        
        return n-max(mxA,mxB);
    }
};
