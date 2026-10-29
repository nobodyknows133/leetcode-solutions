class Solution {

    int n, intime;
    vector<int> tin, tout, val;
    vector<vector<int>> v, up;
    vector<int> tree, lazy;

    void dfs(int u, int p) {
        tin[u] = ++intime;
        up[u][0] = p;

        for (int i = 1; i < 20; i++)
            up[u][i] = up[up[u][i - 1]][i - 1];

        for (int child : v[u])
            if (child != p)
                dfs(child, u);

        tout[u] = intime;
    }

    bool isancestor(int u, int v) { 
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int getlca(int u, int v) {
        if (isancestor(u, v)) return u;
        if (isancestor(v, u)) return v;

        for (int i = 16; i >= 0; i--)
            if (!isancestor(up[u][i], v))
                u = up[u][i];

        return up[u][0];
    }

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] ^= lazy[node];  // XOR update

            if (start != end) {
                lazy[2 * node] ^= lazy[node];
                lazy[2 * node + 1] ^= lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        push(node, start, end);

        if (start > end || start > r || end < l) return;

        if (start >= l && end <= r) {
            lazy[node] ^= val;
            push(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
    }

    int query(int node, int start, int end, int idx) {
        push(node, start, end);

        if (start == end) return tree[node];

        int mid = (end - start)/2 + start;
        if (idx <= mid)
            return query(2 * node, start, mid, idx);
        return query(2 * node + 1, mid + 1, end, idx);
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {

        this->n = n;
        this->intime = 0;

        v.assign(n, {});
        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<int>(20));
        val.resize(n);

        tree.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, 0);

        for (auto i : edges) {
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }

        dfs(0, 0);

        for (int i = 0; i < n; i++) {
            val[i] = (1 << (int(s[i] - 'a')));
            update(1, 1, n, tin[i], tout[i], val[i]);
        }

        vector<bool> anss;

        for (string &qq : queries) {

            stringstream ss(qq);
            string first; 
            ss >> first;

            if (first == "update") {
                int u; 
                char c; 
                ss >> u >> c;

                int newMask = (1 << (c - 'a'));

                int diff = val[u] ^ newMask;

                update(1, 1, n, tin[u], tout[u], diff);

                val[u] = newMask;
            } 
            else {
                int u, v;
                ss >> u >> v;

                int lca = getlca(u, v);

                int xrr = query(1, 1, n, tin[u]) 
                        ^ query(1, 1, n, tin[v]) 
                        ^ val[lca];


                bool ans = ((xrr & (xrr - 1)) == 0);

                anss.push_back(ans);
            }
        }

        return anss;

    }
};
