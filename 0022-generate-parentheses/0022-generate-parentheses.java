class Solution {
    private void solve(List<String> ans, String curr, int n, int open, int close){
        if(curr.length() == 2*n){
            ans.add(curr);
            return;
        }

        if(open < n){
            curr += '(';
            solve(ans, curr, n, open+1, close);
            curr = curr.substring(0, curr.length()-1);
        }

        if(close < open){
            curr += ')';
            solve(ans, curr, n, open, close+1);
            curr = curr.substring(0, curr.length()-1);
        }
    }

    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();

        solve(ans, "", n, 0, 0);
        return ans;
    }
}