class Solution {
private:
    vector<int> findNLE(vector<int>& arr, int n){
        stack<int> st;
        vector<int> nle(n, n);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[i] >= arr[st.top()]) st.pop();
            if(st.empty()) nle[i] = n;
            else nle[i] = st.top();
            st.push(i);
        }
        return nle;
    }
    vector<int> findPLE(vector<int>& arr, int n){
        stack<int> st;
        vector<int> ple(n, -1);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[i] > arr[st.top()]) st.pop();
            if(st.empty()) ple[i] = -1;
            else ple[i] = st.top();
            st.push(i);
        }
        return ple;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size(), MOD = 1e9+7;
        vector<int> nle = findNLE(arr, n);
        vector<int> ple = findPLE(arr, n);
        long long ans = 0;
        for(int i = 0; i < n; i++){
            int right = (nle[i] - i);
            int left = (i - ple[i]);
            ans = ans + (right * left * 1LL * arr[i]);
        }

        return ans;
    }
    vector<int> findNSE(vector<int>& arr, int n){
        stack<int> st;
        vector<int> nse(n, -1);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[i] <= arr[st.top()]) st.pop();
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPSE(vector<int>& arr, int n){
        stack<int> st;
        vector<int> pse(n, -1);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[i] < arr[st.top()]) st.pop();
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr, n);
        vector<int> pse = findPSE(arr, n);
        long long ans = 0;
        for(int i = 0; i < n; i++){
            int right = (nse[i] - i);
            int left = (i - pse[i]);
            ans = ans + (right * left * 1LL * arr[i]);
        }

        return ans;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};