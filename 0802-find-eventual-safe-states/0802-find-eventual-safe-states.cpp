class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& check) {
        vis[node] = 1;
        check[node] = 0;
        pathVis[node] = 1;
        
        for(auto adjNode : graph[node]) {
            if(!vis[adjNode]) {
                if(dfs(adjNode, graph, vis, pathVis, check)) {
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathVis[adjNode]) {
                check[node] = 0;
                return true;
            }
        }

        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0), pathVis(n, 0), checkNodes(n, 0), res;

        for(int node = 0; node < n; node++) {
            if(!vis[node]) {
                dfs(node, graph, vis, pathVis, checkNodes);
            }
        }

        for(int node = 0; node < n; node++) {
            if(checkNodes[node] == 1) res.push_back(node);
        }

        return res;
    }
};