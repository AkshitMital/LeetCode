class Solution {
private:
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
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), MOD = 1e9+7;
        vector<int> nse = findNSE(arr, n);
        vector<int> pse = findPSE(arr, n);
        for(int i = 0; i < n; i++){
            cout << nse[i] << " " << pse[i] << endl;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int right = (nse[i] - i);
            int left = (i - pse[i]);
            ans = (ans + (right * left * 1LL * arr[i] % MOD)) % MOD;
        }

        return ans;
    }
};