class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        set<int> a;
        for(auto s: nums){
            int x = stoi(s,nullptr, 2);
            a.insert(x);
        }

        int i = 1;
        while(i<(1<<16)){
            if(a.find(i)==a.end()){
                return std::bitset<16>(i).to_string().substr(15-n+1,n);//15-x+1 = n
            }
            i++;
        }
        return "";
    }
};
