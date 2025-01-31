class disjoint_set{
public:
    vector<int> parent, size;

    disjoint_set(int n){
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i = 0; i<=n ; i++){
            parent[i] = i;
        }
    }

    int findUlp(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findUlp(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUlp(u);
        int ulp_v = findUlp(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjoint_set ds(n*n);
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,-1,0,1};
        //step 1
        for(int row = 0; row<n; row++){
            for(int col = 0; col<n; col++){
                if(grid[row][col] == 1){
                    for(int i = 0; i < 4; i++){
                        int nrow = row + delrow[i];
                        int ncol = col + delcol[i];

                        if(nrow>=0 && nrow < n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                            int node = (row*n) + col;
                            int adjNode = (nrow*n) + ncol;
                            ds.unionBySize(node,adjNode);
                        }
                    }
                }
            }
        }
        //step 2
        int maxsize = 0;
        for(int row = 0; row<n; row++){
            for(int col = 0; col<n; col++){
                if(grid[row][col] == 0){
                    set<int> components;
                    for(int i = 0; i < 4; i++){
                        int nrow = row + delrow[i];
                        int ncol = col + delcol[i];

                        if(nrow>=0 && nrow < n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                            int adjNode = (nrow*n) + ncol;
                            components.insert(ds.findUlp(adjNode));
                        }
                    }
                    int size = 0;
                    for(auto it : components){
                        size += ds.size[it];
                    }
                    maxsize = max(maxsize,size+1);
                }
            }
        }

        for(int cellNo = 0; cellNo < (n*n) ; cellNo++){
            maxsize = max(maxsize, ds.size[ds.findUlp(cellNo)]);
        }

        return maxsize;
    }
};