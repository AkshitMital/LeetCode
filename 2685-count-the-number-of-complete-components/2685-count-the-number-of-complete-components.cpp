class Solution {
private:
    void dfs(int i, vector<vector<int>>& adj, vector<int>& visited, int& v, int& e) {
        visited[i] = 1;
        v++;
        e += adj[i].size();

        for(int &ngbr : adj[i]) {
            if(!visited[ngbr]) {
                dfs(ngbr, adj, visited, v, e);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int res = 0;

        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);
        for(int node = 0; node < n; node++) {
            if(visited[node] == true) continue;

            int v = 0;
            int e = 0;
            dfs(node, adj, visited, v, e);

            if(v*(v-1)/2 == e/2) res++;
        }

        return res;
    }
};