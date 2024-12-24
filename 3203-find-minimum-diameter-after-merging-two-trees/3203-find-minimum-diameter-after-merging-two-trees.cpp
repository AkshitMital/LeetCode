class Solution {
private:
    pair<int,int> BFS(unordered_map<int, vector<int>> adj, int src) {
        queue<int> q;
        q.push(src);

        unordered_map<int, bool> vis;
        vis[src] = true;

        int farthestNode = src;
        int dist = 0;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int node = q.front();
                q.pop();

                farthestNode = node;

                for(auto adjNode : adj[node]){
                    if(vis[adjNode] == false){
                        vis[adjNode] = true;
                        q.push(adjNode);
                    }
                }
            }

            if(!q.empty()) dist++;
        }

        return {farthestNode, dist};
    }
    int findDiameter(unordered_map<int, vector<int>> adj){
        // step-1: find the farthest node from a random node-0
        auto [farthestNode, dist] = BFS(adj, 0);

        //step-2: find the farthest node from the node we got from above, the distance between them will be the diameter
        auto [otherEnd, diameter] = BFS(adj, farthestNode);

        return diameter;
    }
    
    unordered_map<int, vector<int>> buildAdj(vector<vector<int>>& edges){
        int n = edges.size();
        unordered_map<int, vector<int>> adj(n);

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        return adj;
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = buildAdj(edges1);
        unordered_map<int, vector<int>> adj2 = buildAdj(edges2);

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);
        int combined = (d1+1)/2 + (d2+1)/2 + 1;
        return max({d1, d2, combined});
    }
};