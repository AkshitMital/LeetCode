class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] LIS = new int[n];
        Arrays.fill(LIS, 1);

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]) LIS[i] = Math.max(LIS[j] + 1, LIS[i]);
            }
        }

        int maxi = 0;
        for(int i = 0; i < n; i++){
            maxi = Math.max(maxi, LIS[i]);
        }

        return maxi;
    }
}