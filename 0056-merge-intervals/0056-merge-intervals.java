class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals.length == 0) return new int[0][];
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        List<int[]> ans = new ArrayList<>();
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < intervals.length; i++){
            if(end < intervals[i][0]){
                ans.add(new int[]{start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }else{
                start = Math.min(start, intervals[i][0]);
                end = Math.max(end, intervals[i][1]);
            }
        }

        ans.add(new int[]{start, end});

        return ans.toArray(new int[ans.size()][]);
    }
}