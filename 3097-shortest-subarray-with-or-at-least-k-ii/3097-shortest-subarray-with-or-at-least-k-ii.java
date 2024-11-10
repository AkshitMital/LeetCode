class Solution {
    private int bitsToNum(int[] bits){
        int num = 0;
        for(int i = 0; i < 32; i++){
            if(bits[i] > 0) num |= (1 << i);
        }

        return num;
    }

    public int minimumSubarrayLength(int[] nums, int k) {
        int[] bits = new int[32];
        int r = 0, l = 0, n = nums.length;
        int ans = Integer.MAX_VALUE, xor = 0;

        while (r < n) {
            xor |= nums[r];
            for (int i = 0; i < 32; i++) {
                if ((nums[r] & (1 << i)) != 0) bits[i]++;
            }

            while (xor >= k && l <= r) {
                ans = Math.min(ans, r - l + 1);
                for (int i = 0; i < 32; i++) {
                    if ((nums[l] & (1 << i)) != 0) bits[i]--;
                }
                
                xor = bitsToNum(bits);
                l++;
            }

            r++;
        }
        
        return (ans == Integer.MAX_VALUE) ? -1 : ans;
    }
}