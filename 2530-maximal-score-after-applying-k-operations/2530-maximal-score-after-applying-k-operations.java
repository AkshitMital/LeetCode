class Solution {
    public long maxKelements(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int num : nums) pq.add(num);

        long score = 0;

        while(k-- > 0){
            int num = pq.poll();
            score += num;
            num = (int)Math.ceil(num/3.0);
            pq.add(num);
        }

        return score;
    }
}