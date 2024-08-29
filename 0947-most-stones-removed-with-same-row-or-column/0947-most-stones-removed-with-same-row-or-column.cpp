class DSU{
private:
    vector<int> parent, size;
public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUlp(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUlp(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUlp(u);
        int ulp_v = findUlp(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        }
        else{
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;

        for(auto stone : stones){
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        DSU disjoint_set(maxRow + maxCol + 1);
        unordered_map<int,bool> stoneNodes;

        for(auto stone : stones){
            int RowNode = stone[0];
            int ColNode = stone[1] + maxRow + 1;

            disjoint_set.unionBySize(RowNode, ColNode);
            stoneNodes[RowNode] = true;
            stoneNodes[ColNode] = true;
        }

        int components = 0, n = stones.size();

        for(auto stoneNode : stoneNodes){
            if(disjoint_set.findUlp(stoneNode.first) == stoneNode.first){
                components++;
            }
        }

        return n - components;
    }
};