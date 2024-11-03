class Solution {
    public boolean rotateString(String s, String goal) {
        if(s.length() != goal.length()) return false;

        String temp = s + s;
        System.out.println(temp);

        if(temp.contains(goal)) return true;

        return false;
    }
}