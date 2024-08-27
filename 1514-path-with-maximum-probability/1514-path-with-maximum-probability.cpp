class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<double> max_prob(n, 0.0);
        priority_queue<pair<double,int>> pq;
        pq.push({1.0, start_node});
        max_prob[start_node] = 1.0;

        while(!pq.empty()){
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto& it : adj[node]){
                double temp_prob = it.second;
                int adjNode = it.first;

                if(prob*temp_prob > max_prob[adjNode]){
                    max_prob[adjNode] = prob*temp_prob;
                    pq.push({max_prob[adjNode], adjNode});
                }
            }
        }

        return max_prob[end_node];
    }
};