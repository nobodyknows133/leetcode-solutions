class DisjointSets {
  private:
	vector<int> parents;
	vector<int> sizes;

  public:
	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}

	/** @return the "representative" node in x's component */
	int find(int x) { 
        if(parents[x] == x ){
            return x;
        }
        parents[x] = find(parents[x]);
        return parents[x];
    }

	/** @return whether the merge changed connectivity */
	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}

	/** @return whether x and y are in the same connected component */
	bool connected(int x, int y) { return find(x) == find(y); }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSets dsu(n+5);
        int res = 0;
        for(int i=0;i<n;i++){
            if(dsu.connected(edges[i][0],edges[i][1])){
                res = i;continue;
            }
            else {
                dsu.unite(edges[i][0],edges[i][1]);
            }
        }
        return edges[res];
    }
};
