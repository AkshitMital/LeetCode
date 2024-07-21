class Solution {
private:
    vector<int> topoSort(vector<vector<int>>& edges, int& k){
        vector<vector<int>> adj(k + 1);
        vector<int> indegree(k+1, 0), topo;
        queue<int> q;

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        for(int i = 1; i <= k; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if (topo.size() != k) return {};
        return topo;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> topoRow = topoSort(rowConditions, k);
        vector<int> topoCol = topoSort(colConditions, k);
        vector<vector<int>> res(k, vector<int>(k, 0));

        if(topoRow.empty() || topoCol.empty()) return {};

        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                if(topoRow[i] == topoCol[j]){
                    res[i][j] = topoCol[j];
                }
            }
        }

        return res;
    }
};