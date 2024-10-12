class Solution {
    private int[] findNLE(int[] arr, int n) {
        int[] nle = new int[n];
        Stack<Integer> st = new Stack<>();
        for(int i = n-1; i >= 0; i--) {
            while(!st.isEmpty() && arr[i] > arr[st.peek()]) st.pop();
            if(st.isEmpty()) nle[i] = n;
            else nle[i] = st.peek();
            st.push(i);
        }

        return nle;
    }
    private int[] findPLE(int[] arr, int n) {
        int[] ple = new int[n];
        Stack<Integer> st = new Stack<>();
        for(int i = 0; i < n; i++) {
            while(!st.isEmpty() && arr[i] >= arr[st.peek()]) st.pop();
            if(st.isEmpty()) ple[i] = -1;
            else ple[i] = st.peek();
            st.push(i);
        }

        return ple;
    }
    private long sumSubarrayMax(int[] arr) {
        int n = arr.length;
        int[] nle = findNLE(arr, n);
        int[] ple = findPLE(arr, n);

        long ans = 0;
        for(int i = 0; i < n; i++){
            int right = nle[i] - i;
            int left = i - ple[i];

            ans = ans + (long) right * left * arr[i];
        }

        return ans;
    }

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
            while(!st.isEmpty() && arr[i] <= arr[st.peek()]) st.pop();
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.peek();

            st.push(i);
        }

        return pse;
    }

    private long sumSubarrayMins(int[] arr) {
        int n = arr.length;
        int[] nse = findNSE(arr, n);
        int[] pse = findPSE(arr, n);

        long ans = 0;
        for(int i = 0; i < n; i++){
            int right = nse[i] - i;
            int left = i - pse[i];

            ans = (ans + (long) right * left * arr[i]);
        }

        return ans;
    }

    public long subArrayRanges(int[] nums) {
        return (long) sumSubarrayMax(nums) - sumSubarrayMins(nums);
    }
}