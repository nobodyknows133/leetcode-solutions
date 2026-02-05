class Solution {
public:
    typedef long long ll;
    ll res = -1*1e15;
    int n;
    vector<vector<ll>> dp;
    ll solve(int ind, int tr,vector<int>& nums){
        if(ind>=n){
            if(tr==3){
                return 0;
            }
            else{
                return LLONG_MIN/2;
            }
        }
        if(dp[ind][tr]!=LLONG_MIN){
            return dp[ind+1][tr];
        }
        ll skip = LLONG_MIN/2;
        ll take = LLONG_MIN/2;
        if(tr==0){
            skip = solve(ind+1,tr,nums);
        }
        if(tr==3){
            take = nums[ind];
        }
        
        if(ind+1<n){
            int curr = nums[ind];
            int nxt = nums[ind+1];

            if(tr==0 && nxt > curr){
                take = max(take,curr + solve(ind+1,1,nums));
            }
            else if(tr==1){
                if(nxt > curr){
                    take = max(take,curr+solve(ind+1,1,nums));
                }
                else if(nxt < curr){
                    take = max(take,curr+solve(ind+1,2,nums));
                }
            }
            else if(tr==2){
                if(nxt < curr){
                    take = max(take,curr+solve(ind+1,2,nums));
                }
                else if(nxt > curr){
                    take = max(take,curr+solve(ind+1,3,nums));
                }
            }
            else if(tr==3){
                if(nxt > curr){
                    take = max(take,curr+solve(ind+1,3,nums));
                }
            }
        }


        dp[ind+1][tr] = max(take,skip);
        return dp[ind+1][tr];
    }
    ll maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        dp.assign(n+1,vector<ll>(4,LLONG_MIN));

        return solve(0,0,nums);
        
    }
};
