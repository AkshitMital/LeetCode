class Solution {
    public boolean canJump(int[] nums) {
        int i = 0, maxInd = 0, currEnd = 0, n = nums.length, cnt = 0;
        while(i < n){
            cnt++;
            while(i <= currEnd){
                maxInd = Math.max(maxInd, nums[i] + i);
                i++;
                if(maxInd >= n-1) return true;
            }
            if(maxInd == currEnd) return false;
            currEnd = maxInd;
        }

        return true;
    }
}