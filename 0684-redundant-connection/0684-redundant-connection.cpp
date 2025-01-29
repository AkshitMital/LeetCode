class DSU {
private:
    vector<int> size, parent;
public:
    DSU(int n) {
        size.resize(n + 1);
        parent.resize(n + 1);

        for(int i = 0; i < n + 1; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUlp(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findUlp(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUlp(u);
        int ulp_v = findUlp(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if(dsu.findUlp(u) == dsu.findUlp(v)) return {u, v};
            else dsu.unionByRank(u, v);
        }

        return {-1};
    }
};