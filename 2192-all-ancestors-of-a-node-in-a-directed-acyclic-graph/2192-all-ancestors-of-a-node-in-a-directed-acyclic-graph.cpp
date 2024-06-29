class Solution {
private:
    vector<int> topoSort(int n, vector<vector<int>>& edges, vector<vector<int>>& adj){
        vector<int> indegree(n,0);
        for(auto it : edges) indegree[it[1]]++;

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        return topo;
    }

    void solve(vector<vector<int>>& ans, vector<vector<int>>& adj, int n, vector<int>& topo){
        vector<unordered_set<int>> vec(n);

        for(int& node : topo){
            for(int& v : adj[node]){
                vec[v].insert(node);//adding node ancestor
                vec[v].insert(vec[node].begin(), vec[node].end());//adding ancestors of the ancestors of the node
            }
        }

        for(int i = 0; i < n; i++){
            ans[i] = vector<int>(vec[i].begin(), vec[i].end());
            sort(ans[i].begin(), ans[i].end());
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges) adj[it[0]].push_back(it[1]);

        vector<int> topo = topoSort(n, edges, adj);

        vector<vector<int>> ans(n);
        solve(ans, adj, n, topo);

        return ans;
    }
};