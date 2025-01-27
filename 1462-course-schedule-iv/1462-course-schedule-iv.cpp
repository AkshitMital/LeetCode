class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(auto& prerequisite : prerequisites) {
            adj[prerequisite[0]].push_back(prerequisite[1]);
            indegree[prerequisite[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        unordered_map<int, unordered_set<int>> mpp;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto adjNode : adj[node]) {
                mpp[adjNode].insert(node);

                for(auto& preq : mpp[node]) mpp[adjNode].insert(preq);

                indegree[adjNode]--;
                if(indegree[adjNode] == 0) q.push(adjNode);
            }
        }
        
        vector<bool> ans;
        for(auto& query : queries) {
            int preq = query[0];
            int course = query[1];

            if(mpp[course].find(preq) != mpp[course].end()) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};