class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0;
        char prev = '0';
        for(auto ch: s){
            if(ch=='1' && prev=='0'){
                cnt++;
            }
            prev = ch;
        }
        return cnt<=1;
    }
};
