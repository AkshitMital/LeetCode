class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        int grpnum = 0;
        unordered_map<int, int> num2Grp;
        num2Grp[temp[0]] = grpnum;

        unordered_map<int, list<int>> grp2List;
        grp2List[grpnum].push_back(temp[0]);

        for(int i = 1; i < n; i++) {
            if(abs(temp[i] - temp[i - 1]) > limit) grpnum++;

            num2Grp[temp[i]] = grpnum;
            grp2List[grpnum].push_back(temp[i]);
        }

        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            int grpIdx = num2Grp[num];

            res[i] = *(grp2List[grpIdx].begin());
            grp2List[grpIdx].pop_front();
        }

        return res;
    }
};