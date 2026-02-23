class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> subs;
        int n = s.size();
        for(int i=0;i+k-1<=n-1;i++){
            string ss = s.substr(i,k);
            subs.insert(ss);
        }
        return subs.size()==(int)pow(2,k);
    }
};
