class Solution {
private:
    int findShortestDistance(vector<int> adj[], int n){
        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();
                q.pop();
                if(node == n-1) return level;
                for (int adjNode : adj[node]) {
                    if (!visited[adjNode]) {
                        visited[adjNode] = true;
                        q.push(adjNode);
                    }
                }
            }
            level += 1;
        }

        return -1;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> adj[n];
        for(int i = 0; i < n-1; i++) adj[i].push_back(i+1);

        int q = queries.size();
        vector<int> shortDist(q, -1);
        for(int i = 0; i < q; i++){
            adj[queries[i][0]].push_back(queries[i][1]);
            shortDist[i] = findShortestDistance(adj, n);
        }

        return shortDist;
    }
};