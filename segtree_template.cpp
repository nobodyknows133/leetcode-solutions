#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
struct item{
    int m,c;
};
struct segtree{
    int size;
    vector<item> values;
 
    item combine(item a, item b){
        if(a.m < b.m) return a;
        if(b.m < a.m) return b;
        if(a.m==b.m) return {a.m, a.c + b.c};
        return {0,0};    
    }
 
    void init(int n){
        size = 1;
        while(size<n) size*=2;
        values.resize(2*size);
    }
 
    void build(vector<int> &a){
        size = 1;
        while(size<(int)a.size()) size*=2;
        values.resize(2*size);
        build(a,0,0,size);
    }
 
    void build(vector<int> &a,int x, int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)a.size())
            {
                values[x]={a[lx],1};
            }
            return;
        }
 
        int mx = (lx + rx) / 2;
        build(a,2*x+1, lx, mx);
        build(a,2*x+2, mx, rx);
        values[x] = combine(values[2*x+1], values[2*x+2]);
    }
 
    void set(int i, int v){
        set(i,v,0,0,size);
    }
 
    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            if(x<values.size()){
                values[x]={v,1};
                return;
            }           
        }
 
        int mx = (lx + rx) / 2;
        if(i<mx) set(i,v,2*x+1,lx,mx);
        else set(i,v,2*x+2,mx,rx);
        values[x]=combine(values[2*x+1],values[2*x+2]);
    }
 
    item calc(int l, int r){
        return calc(l,r,0,0,size);
    }
 
    item calc(int l, int r,int x, int lx, int rx){
        if(lx>=r || rx<=l){
            return {(int)1e9+6,1};
        }
        
        if(lx>=l && rx<=r){
            return values[x];
        }
 
        int mx = (lx + rx)/2;
        auto left = calc(l,r,2*x+1,lx,mx);
        auto right = calc(l,r,2*x+2,mx,rx);
        return combine(left,right);
    }
};
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n,m;
    cin>>n>>m;
    segtree st;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    st.build(a);
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
            auto res = st.calc(l,r);
            cout<<res.m<<" "<<res.c<<"\n";
        }
    }
 
    return 0;
}
