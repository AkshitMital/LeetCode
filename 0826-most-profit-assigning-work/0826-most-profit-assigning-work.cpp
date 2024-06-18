class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        unordered_map<int,int> mpp;
        int maxi = INT_MIN;
        for(int i = 0; i < difficulty.size(); i++){
            mpp[difficulty[i]] = max(mpp[difficulty[i]], profit[i]);
            maxi = max(maxi, difficulty[i]);
        }
        vector<int> arr(maxi+1, 0);
        if(mpp.find(0) != mpp.end()) arr[0] = mpp[0];
        for(int i = 1; i <= maxi; i++){
            arr[i] = max(arr[i - 1], mpp[i]);
        }
        int ans = 0;
        for(auto it : worker){
            if(it > maxi){
                ans += arr[maxi];
                continue;
            }
            ans += arr[it];
        }

        return ans;
    }
};