class Solution {
// private:
//     vector<int> computeNSE(vector<int>& heights, int n){
//         vector<int> nse(n, n);
//         stack<int> st;
//         for(int i = n-1; i >= 0; i--){
//             while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
//             if(st.empty()) nse[i] = n;
//             else nse[i] = st.top();
//             st.push(i);
//         }
//         return nse;
//     }

//     vector<int> computePSE(vector<int>& heights, int n){
//         vector<int> pse(n, 0);
//         stack<int> st;
//         for(int i = 0; i < n; i++){
//             while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
//             if(st.empty()) pse[i] = -1;
//             else pse[i] = st.top();
//             st.push(i);
//         }
//         return pse;
//     }
public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> nse = computeNSE(heights, n);
//         vector<int> pse = computePSE(heights, n);

//         for(int i = 0; i < n; i++){
//             cout << nse[i] << " " << pse[i] << endl;
//         }

//         int maxArea = 0;
//         for(int i = 0; i < n; i++){
//             int area = (nse[i] - pse[i] - 1) * heights[i];
//             maxArea = max(maxArea, area);
//         }

//         return maxArea;
//     }

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