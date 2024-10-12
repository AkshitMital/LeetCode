class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int top = st.top();
                st.pop();
                int nse = i;
                int pse = (st.empty()) ? -1 : st.top();
                int tempArea = heights[top] * (nse - pse - 1);
                maxArea = max(tempArea, maxArea);
            }

            st.push(i);
        }

        while(!st.empty()){
            int top = st.top();
            st.pop();
            int nse = n;
            int pse = (st.empty()) ? -1 : st.top();
            int tempArea = heights[top] * (nse - pse - 1);
            maxArea = max(tempArea, maxArea);
        }

        return maxArea;
    }
};