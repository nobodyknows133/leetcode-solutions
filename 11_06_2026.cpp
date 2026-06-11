class Solution {
public:

    int dp[((int)1e5+5)][2];
    vector<int> adj[((int)1e5+5)];
    int h[((int)1e5+5)];
    int mxHt = -1;
    const int mod = 1e9+7;

    void dfs(int u, int p){
        if(p!=-1){
            h[u]=h[p]+1;
            
            dp[u][0]=(dp[p][0]+dp[p][1])%mod;
            dp[u][1]=(dp[p][0]+dp[p][1])%mod;
        }
        mxHt = max(mxHt,h[u]);
        for(int v: adj[u]){
            if(v!=p){
                dfs(v,u);
            }
        }
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        h[1]=0;
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dp[1][0]=1;
        dp[1][1]=0;

        dfs(1,-1);

        for(int i=1;i<=edges.size()+1;i++){
            if(h[i]==mxHt){
                return dp[i][1];
            }
        }
        return 0;
    }
};
