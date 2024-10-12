class Solution {
    private int[] findNSE(int[] arr, int n){
        int[] nse = new int[n];
        Stack<Integer> st = new Stack<>();

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[i] < arr[st.peek()]) st.pop();
            if(st.empty()) nse[i] = n;
            else nse[i] = st.peek();

            st.push(i);
        }

        return nse;
    }

    private int[] findPSE(int[] arr, int n){
        int[] pse = new int[n];
        Stack<Integer> st = new Stack<>();

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[i] <= arr[st.peek()]) st.pop();
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.peek();

            st.push(i);
        }

        return pse;
    }

    public int sumSubarrayMins(int[] arr) {
        int n = arr.length;
        int[] nse = findNSE(arr, n);
        int[] pse = findPSE(arr, n);

        int ans = 0;
        int MOD = (int) 1e9+7;
        for(int i = 0; i < n; i++){
            int right = nse[i] - i;
            int left = i - pse[i];

            ans = (int)(ans + (long) (arr[i] * right * left) % MOD) % MOD;
        }

        return ans;
    }
}