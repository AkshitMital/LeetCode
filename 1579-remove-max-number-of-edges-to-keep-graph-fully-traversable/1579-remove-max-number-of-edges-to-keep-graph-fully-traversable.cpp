class disjoint_set{
public:
    vector<int> parent, size;
    int components;
    disjoint_set(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        components = n;
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    int findUlp(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUlp(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUlp(u);
        int ulp_v = findUlp(v);

        if(ulp_u == ulp_v) return;
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        components--;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        disjoint_set Alice(n);
        disjoint_set Bob(n);
        int edgeCount = 0;
        for(auto& vec : edges){
            int type = vec[0];
            int u = vec[1];
            int v = vec[2];

            if(type == 3){
                bool addEdge = false;
                if(Alice.findUlp(u) != Alice.findUlp(v)){
                    Alice.unionBySize(u,v);
                    addEdge = true;
                }
                if(Bob.findUlp(u) != Bob.findUlp(v)){
                    Bob.unionBySize(u,v);
                    addEdge = true;
                }
                if(addEdge == true) edgeCount++;
            }
            else if(type == 2){
                if(Bob.findUlp(u) != Bob.findUlp(v)){
                    Bob.unionBySize(u,v);
                    edgeCount++;
                }
            }
            else{
                if(Alice.findUlp(u) != Alice.findUlp(v)){
                    Alice.unionBySize(u,v);
                    edgeCount++;
                }
            }
        }

        if(Alice.components==1 && Bob.components==1) return edges.size() - edgeCount;

        return -1;
    }
};