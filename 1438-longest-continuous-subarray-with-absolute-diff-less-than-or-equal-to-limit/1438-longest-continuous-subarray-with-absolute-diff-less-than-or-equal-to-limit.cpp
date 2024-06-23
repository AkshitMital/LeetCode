class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        multiset<int> mst;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_pq;

        int i = 0, j = 0, ans = 0;

        while(j < n){
            mst.insert(nums[j]);

            if(*mst.rbegin() - *mst.begin() > limit){
                mst.erase(mst.find(nums[i]));
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};