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

        int[] arr = new int[st.size()];
        for (int i = st.size() - 1; i >= 0; i--) { 
            arr[i] = st.pop();
        }
        return arr;
    }
}