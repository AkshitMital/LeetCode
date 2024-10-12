class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> st = new Stack<>();
        for(int size : asteroids){
            boolean exploded = false;
    
            while(!st.isEmpty() && size < 0 && st.peek() > 0){
                if(Math.abs(size) == Math.abs(st.peek())){
                    st.pop();
                    exploded = true;
                    break;
                }
                else if (Math.abs(st.peek()) > Math.abs(size)) {
                    exploded = true;
                    break;
                } else {
                    st.pop();
                }
            }

            if(!exploded) st.add(size);
        }

        ArrayList<Integer> arr = new ArrayList<>();

        while (!st.isEmpty()) { 
            arr.add(st.pop());
        }

        Collections.reverse(arr);  

        int[] ans = new int[arr.size()];

        for (int i = 0; i < arr.size(); i++) {
            ans[i] = arr.get(i);
        }

        return ans;
    }
}