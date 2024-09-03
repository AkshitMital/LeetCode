class Solution {
private:
    vector<int> solve(vector<int>& nums){
        stack<int> st;
        vector<int> nge(nums.size(), -1);
        int i = nums.size() - 1;
        for(int i = nums.size()-1; i >= 0; i--){
            while(!st.empty() && st.top() < nums[i]) st.pop();
            if(st.empty()) nge[i] = -1;
            else nge[i] = st.top();
            st.push(nums[i]);
        }

        return nge;
    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp; // number -> index
        for(int i = 0; i < nums2.size(); i++) mpp[nums2[i]] = i;

        vector<int> nge = solve(nums2);
        vector<int> ans;
        for(auto num : nums1){
            ans.push_back(nge[mpp[num]]);
        }

        return ans;

    }
};