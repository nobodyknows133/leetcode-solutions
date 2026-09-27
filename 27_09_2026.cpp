class Solution {
public:
    int ind = 0;
    int n = 0;
    string ss = "";
    string f(string curr){
        if(ind >= ss.size()){
            return curr;
        }
        
        while(ind<ss.size()){
            if(ss[ind]==')'){
                // reached end of call, reverse and return
                reverse(begin(curr),end(curr));
                ind++;
                return curr;
             }

            else if(ss[ind]=='('){
                // recursive call
                ind++;
                curr += f("");
            }

            else {
                curr += ss[ind];
                ind++;
            }
        }

        return curr;
    }
    string reverseParentheses(string s) {
        n = s.size();
        ss = s;
        return f(""); 
    }
};
