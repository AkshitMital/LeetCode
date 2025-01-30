class Solution {
private:
    bool isBipartite(vector<vector<int>>& adj, int node, vector<int>& colors, int currColor) {
        colors[node] = currColor;

        for(int& adjNode : adj[node]) {
            if(colors[adjNode] == colors[node]) return false;

            if(colors[adjNode] == -1) {
                if(!isBipartite(adj, adjNode, colors, 1 - currColor)) return false;
            }
        }

        return true;
    }

    int bfs(vector<vector<int>>& adj, int currNode, int n) {
        queue<int> q;
        q.push(currNode);
        vector<bool> vis(n, false);
        vis[currNode] = true;
        int level = 1;

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int node = q.front();
                q.pop();

                for(int& adjNode : adj[node]) {
                    if(vis[adjNode]) continue;

                    q.push(adjNode);
                    vis[adjNode] = true;
                }
            }

            level++;// 1 will be incremented in the last loop
        }

        return level - 1;
    }

    int getMaxEachFromComp(vector<vector<int>>& adj, int node, vector<bool>& vis, vector<int>& levels) {
        int maxGrp = levels[node];
        vis[node] = true;

        for(int& adjNode : adj[node]) {
            if(!vis[adjNode]) {
                maxGrp = max(maxGrp, getMaxEachFromComp(adj, adjNode, vis, levels));
            }
        }

        return maxGrp;
    }

public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto& edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> colors(n, -1);
        for(int node = 0; node < n; node++) {
            if(colors[node] == -1) {
                if(!isBipartite(adj, node, colors, 1)) return -1;
            }
        }

        vector<int> levels(n, 0);
        for(int node = 0; node < n; node++) {
            levels[node] = bfs(adj, node, n);
        }

        int maxGrp = 0;
        vector<bool> vis(n, false);
        for(int node = 0; node < n; node++) {
            if(!vis[node]) {
                maxGrp += getMaxEachFromComp(adj, node, vis, levels);
            }
        }

        return maxGrp;
    }
};