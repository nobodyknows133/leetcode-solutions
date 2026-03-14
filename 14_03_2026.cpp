#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

using namespace __gnu_pbds;


typedef tree<
    string,
    null_type,
    std::less<string>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

class Solution {
public:
    // Define an ordered set with order statistics
    ordered_set s;
    int N = 0;
    char l[3] = {'a','b','c'};
    void go(string curr, char prev){
        if((int)curr.size() == N ){
            s.insert(curr);
            return;
        }
        for(int i=0;i<=2;i++){
            if(l[i]==prev) continue;
            else go(curr+l[i],l[i]);
        }
        
    }
    string getHappyString(int n, int k) {
        N = n;

        go("",'!');
        if(s.size()>=k) return *s.find_by_order(k - 1);
        else return "";
    }
};
