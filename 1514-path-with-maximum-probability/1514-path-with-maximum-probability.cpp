class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        priority_queue<pair<double,int>> pq;
        vector<double> max_prob(n, 0.0);
        pq.push({1.0, start_node});
        max_prob[start_node] = 1.0;

        while(!pq.empty()){
            double currProb = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for(auto& [node, prob] : adj[currNode]){
                if(prob*currProb > max_prob[node]){
                    max_prob[node] = prob*currProb;
                    pq.push({max_prob[node], node});
                }
            }
        }

        return max_prob[end_node];
    }
};