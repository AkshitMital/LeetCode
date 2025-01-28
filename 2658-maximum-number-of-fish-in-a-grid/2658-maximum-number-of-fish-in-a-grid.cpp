class DSU {
private:
    vector<int> parent, size;
public:
    DSU(int sz, vector<vector<int>> grid) {
        size.resize(sz);
        parent.resize(sz);
        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < sz; i++) {
            parent[i] = i;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) {
                    int idx = (n*i) + j;
                    size[idx] = grid[i][j];
                }
            }
        }
    }

    int findUlp(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findUlp(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUlp(u);
        int ulp_v = findUlp(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] >= size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }

    int getMaxFish() {
        return *max_element(size.begin(), size.end());
    }
};

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        DSU dsu(n*m, grid);
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] > 0) {
                    int idx = (n * row) + col;
                    for(auto& dir : directions) {
                        int nrow = row + dir[0];
                        int ncol = col + dir[1];
                        if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] > 0) {
                            int nidx = (n * nrow) + ncol;
                            dsu.unionBySize(idx, nidx);
                        }
                    }
                }
            }
        }

        return dsu.getMaxFish();
    }
};