class Solution { 
    private int[] getLIS(int[] nums, int n) {
        int[] LIS = new int[n];
        Arrays.fill(LIS, 1);

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]) LIS[i] = Math.max(LIS[j] + 1, LIS[i]);
            }
        }

        return LIS;
    }

    private int[] getLDS(int[] nums, int n) {
        int[] LDS = new int[n];
        Arrays.fill(LDS, 1);

        for(int i = n-2; i >= 0; i--){
            for(int j = n-1; j > i; j--){
                if(nums[i] > nums[j]) LDS[i] = Math.max(LDS[j] + 1, LDS[i]);
            }
        }

        return LDS;
    }
    public int minimumMountainRemovals(int[] nums) {
        int n = nums.length;
        int[] LIS = getLIS(nums, n);
        for(int x : LIS) System.out.printf(x + " ");
        System.out.println("\n");
        int[] LDS = getLDS(nums, n);
        for(int x : LDS) System.out.printf(x + " ");
        System.out.println("\n");

        int mini = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++){
            if(LIS[i] <= 1 || LDS[i] <= 1) continue;
            mini = Math.min(mini, n - LIS[i] - LDS[i] + 1);
        }
        System.out.println(mini);
        return mini;
    }
}