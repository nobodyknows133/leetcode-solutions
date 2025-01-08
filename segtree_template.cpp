#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct segtree{
    int size;
    vector<ll> sums;

    void init(int n){
        size = 1;
        while(size<n) size*=2;
        sums.assign(2*size,0LL);
    }

    void set(int i, int v){
        set(i,v,0,0,size);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            if(x<sums.size()){
                sums[x]=v;
                return;
            }           
        }

        int mx = (lx + rx) / 2;
        if(i<mx) set(i,v,2*x+1,lx,mx);
        else set(i,v,2*x+2,mx,rx);

        sums[x]=sums[2*x+1] + sums[2*x+2];
    }

    ll sum(int l, int r){
        return sum(l,r,0,0,size);
    }

    ll sum(int l, int r,int x, int lx, int rx){
        // out of bounds so can skip
        if(lx>=r || rx<=l){
            return 0LL;
        }
        
        // completely lies inside
        if(lx>=l && rx<=r){
            return sums[x];
        }

        int mx = (lx + rx)/2;
        ll left = sum(l,r,2*x+1,lx,mx);
        ll right = sum(l,r,2*x+2,mx,rx);
        return left + right;
    }


};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    segtree st;
    st.init(n);

    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        st.set(i,x);
    }

    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int i,v;
            cin>>i>>v;
            st.set(i,v);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<st.sum(l,r)<<"\n";
        }
    }

    return 0;
}
