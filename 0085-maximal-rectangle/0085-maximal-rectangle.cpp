class Solution {
private:
    int solve(vector<int>& arr){
        stack<int> st;
        int n = arr.size(), maxArea = INT_MIN;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[i] < arr[st.top()]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = (!st.empty()) ? st.top() : -1;
                maxArea = max(maxArea, (nse-pse-1) * arr[element]);
            }
            st.push(i);
        }

        while(!st.empty()){
            int element = st.top();
            st.pop();
            int nse = n;
            int pse = (!st.empty()) ? st.top() : -1;
            maxArea = max(maxArea, (nse-pse-1) * arr[element]);
        }

        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if (rows == 0) return 0;
        vector<int> heights(cols, 0);
        int maxArea = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            int area = solve(heights);
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};