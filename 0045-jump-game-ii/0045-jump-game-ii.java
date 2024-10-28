class Solution {
    public int jump(int[] nums) {
        int i = 0, maxInd = 0, currEnd = 0, n = nums.length, cnt = 0;
        if(n <= 1) return 0;
        while(i < n){
            cnt++;
            while(i <= currEnd){
                maxInd = Math.max(maxInd, nums[i] + i);
                i++;
                if(maxInd >= n-1) return cnt;
            }
            if(maxInd == currEnd) return -1;
            currEnd = maxInd;
        }

        return cnt;
    }
}