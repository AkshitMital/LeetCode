class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(2*n, -1);
        stack<int> st;
        vector<int> temp = nums;
        for(int& num : nums) temp.push_back(num);

        for(int i = (2*n-1); i >= 0; i--){
            while(!st.empty() && st.top() <= temp[i]) st.pop();
            if(!st.empty()) nge[i] = st.top();
            st.push(temp[i]);
        }

        vector<int> ans(nge.begin(), nge.begin() + n);
        return ans;
    }
};