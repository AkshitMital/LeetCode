class DSU {
public:
    vector<int> parent, size, weights;
    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        weights.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
            weights[i] = -1;
        }
    }

    int findUlp(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findUlp(parent[node]);
    }

    void unionBySize(int u, int v, int wt) {
        int ulp_u = findUlp(u);
        int ulp_v = findUlp(v);

        if(ulp_u == ulp_v) {
            weights[ulp_u] &= wt;
            return;
        }
        
        if(size[ulp_u] > size[ulp_v]) {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
            weights[ulp_u] &= weights[ulp_v];
            weights[ulp_u] &= wt;
        } else {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
            weights[ulp_v] &= weights[ulp_u];
            weights[ulp_v] &= wt;
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        DSU dsu(n);

        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            dsu.unionBySize(u, v, wt);
        }

        vector<int> ans;
        for(auto& query : queries) {
            int u = query[0];
            int v = query[1];
            if(u == v) {
                ans.push_back(0);
                continue; // Use continue instead of break
            }

            int ulp_u = dsu.findUlp(u);
            int ulp_v = dsu.findUlp(v);

            if(ulp_u != ulp_v) ans.push_back(-1);
            else ans.push_back(dsu.weights[ulp_u]);
        }

        return ans;
    }
};