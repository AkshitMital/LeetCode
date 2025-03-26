class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> box;
        for(auto& bx : grid) {
            for(auto& element : bx) box.push_back(element);
        }

        int n = box.size();
        sort(box.begin(), box.end());
        int median = 0;
        median = box[(n - 1)/2];
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int diff = abs(box[i] - median);
            if(diff % x != 0) return -1;
            ans += (diff/x);
        }

        return ans;
    }
};