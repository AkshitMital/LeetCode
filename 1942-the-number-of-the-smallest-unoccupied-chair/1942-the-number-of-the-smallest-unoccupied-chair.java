class Solution {
    public int smallestChair(int[][] times, int targetFriend) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a, b) -> a[0]-b[0]
        );

        TreeSet<Integer> freeChair = new TreeSet<>();
        int targetArrivalTime = times[targetFriend][0];

        Arrays.sort(times, (a, b) -> a[0] - b[0]);

        int chair = 0, targetChair = 0;
        for(int[] time : times){
            int arrival = time[0];
            int departure = time[1];

            while(!pq.isEmpty() && pq.peek()[0] <= arrival){
                freeChair.add(pq.poll()[1]);
            }

            int assignedChair = 0;
            if(freeChair.isEmpty()){
                assignedChair = chair++;
            }else{
                assignedChair = freeChair.first();
                freeChair.remove(assignedChair);
            }

            if(arrival == targetArrivalTime) return assignedChair;

            pq.offer(new int[]{departure, assignedChair});
        }

        return -1;
    }
}