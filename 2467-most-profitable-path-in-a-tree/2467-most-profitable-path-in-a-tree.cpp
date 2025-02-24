class Solution {
private:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> bobMap;
    int aliceIncome;

    bool DFSBob(int curr, int time, vector<bool>& vis) {
        vis[curr] = true;
        bobMap[curr] = time;

        if(curr == 0) return true;

        for(auto& ngbr : adj[curr]) {
            if(!vis[ngbr]) {
                if(DFSBob(ngbr, time + 1, vis) == true) return true;
            }
        }

        bobMap.erase(curr);
        return false;
    }

    void DFSAlice(int curr, int time, vector<bool>& vis, vector<int>& amount, int income) {
        vis[curr] = true;

        if(bobMap.find(curr) == bobMap.end() || time < bobMap[curr]) {
            income += (amount[curr]);
        } else if (time == bobMap[curr]) income += (amount[curr] / 2);

        if(adj[curr].size() == 1 && curr != 0) aliceIncome = max(aliceIncome, income);

        for(auto& ngbr : adj[curr]) {
            if(!vis[ngbr]) {
                DFSAlice(ngbr, time + 1, vis, amount, income);
            }
        }
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();

        aliceIncome = INT_MIN;
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int time = 0;
        vector<bool> vis(n, false);
        DFSBob(bob, time, vis);

        int income = 0;
        vis.assign(n, false);
        DFSAlice(0, time, vis, amount, income);

        return aliceIncome;
    }
};