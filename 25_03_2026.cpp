class Solution {
    // using int = long long;
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m<=1 && n<=1){
            return false;
        }

        long long colSums[n];
        long long rowSums[m];
        long long rowPre[m];
        long long colPre[n];

        for(int i=0;i<n;i++){
            colSums[i]=0;
            for(int j=0;j<m;j++){
                colSums[i]+=grid[j][i];
            }
            if(i>0){
                colPre[i]=colSums[i]+colPre[i-1];
            }
            else colPre[i]=colSums[i];
        }

        for(int i=0;i<m;i++){
            rowSums[i]=0;
            for(int j=0;j<n;j++){
                rowSums[i]+=grid[i][j];
            }
            if(i>0){
                rowPre[i]=rowSums[i]+rowPre[i-1];
            }
            else rowPre[i]=rowSums[i];
        }

        bool res = false;

        for(int i=0;i<m-1;i++){
            if(rowPre[i]==rowPre[m-1]-rowPre[i]){
                res = true;
            }
        }

        for(int i=0;i<n-1;i++){
            if(colPre[i]==colPre[n-1]-colPre[i]){
                res = true;
            }
        }

        return res;
        
    }
};
