class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathvis, vector<int>& check){
        vis[node] = 1;
        pathvis[node] = 1;

        for(auto it : graph[node]) {
            if(!vis[it]) {
                if(dfs(it,graph,vis,pathvis,check)==true){
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathvis[it]){
                check[node] = 0;
                return true;
            }
        }

        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> check(n,0);
        vector<int> safenodes;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathvis,check);
            }
        }
        for(int i=0; i<n; i++){
            if(check[i]==1) safenodes.push_back(i);
        }
        return safenodes;
    }
};