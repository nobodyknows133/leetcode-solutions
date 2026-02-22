class Solution {
public:
    int binaryGap(int n) {
        bitset<32> b(n);
        vector<int> pos;
        for(int i=0;i<32;i++){
            if(b[i]==1) pos.push_back(i);
        }
        
        int res = 0;
        if(pos.size()>=2){
            for(int i=1;i<pos.size();i++){
                res = max(res,pos[i]-pos[i-1]);
            }
        }
        return res;
    }
};
