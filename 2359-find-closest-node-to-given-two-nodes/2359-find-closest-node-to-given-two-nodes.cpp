class Solution {
private:
    int n;
    void bfs(vector<int>& edges, int node, vector<int>& dist) {
        queue<int> q;
        q.push(node);
        dist[node] = 0;
        vector<bool> visited(n, false);
        visited[node] = true;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            int v = edges[u];

            if(v != -1 && !visited[v]) {
                visited[v] = true;
                dist[v] = 1 + dist[u];
                q.push(v);
            }
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);

        bfs(edges, node1, dist1);
        bfs(edges, node2, dist2);

        int minDist = INT_MAX;
        int minNode = -1;

        for(int i = 0; i < n; i++) {
            int maxd = max(dist1[i], dist2[i]);

            if(minDist > maxd) {
                minDist = maxd;
                minNode = i;
            }
        }
        
        return minNode;
    }
};