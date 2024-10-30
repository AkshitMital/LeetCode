class Solution {
    private int lower_bound(List<Integer> lis, int key){
        int low = 0, high = lis.size()-1, mid = 0;
        while(low < high){
            mid = low + (high - low)/2;
            if(lis.get(mid) < key) low = mid + 1;
            else high = mid;
        }

        // if (low < lis.size() && lis.get(low) < key) {
        //     low++;
        // }

        return low;
    }
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        List<Integer> lis = new ArrayList<>();
        lis.add(nums[0]);

        for(int i = 1; i < n; i++){
            if(lis.get(lis.size() - 1) < nums[i]) lis.add(nums[i]);
            else{
                int idx = lower_bound(lis, nums[i]);
                lis.set(idx, nums[i]);
            }
        }

        return lis.size();
    }
}