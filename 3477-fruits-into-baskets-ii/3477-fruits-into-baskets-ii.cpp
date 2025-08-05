class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> vis(n, 0);
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int j = 0;
            for(; j < n; j++) {
                if(!vis[j] && fruits[i] <= baskets[j]) {
                    cout << fruits[i] << " " << baskets[j] << endl;
                    // if(vis[j]) ans++;
                    // else {
                        vis[j] = 1;
                        break;
                    // }
                }
            }
            if(j == n) ans++;
        }

        return ans;
    }
};