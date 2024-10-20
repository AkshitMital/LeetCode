class Solution {
private:
    bool isValid(string curr){
        int count = 0;

        for(char ch : curr){
            if(ch == '(') count++;
            else count--;
            
            if(count < 0) return false;
        }

        return (count == 0);
    }
    void solve(string curr, int n, vector<string>& ans){
        if(curr.length() == 2*n){
            if(isValid(curr)){
                ans.push_back(curr);
            }

            return;
        }

        curr += '(';
        solve(curr, n, ans);
        curr.pop_back();

        curr += ')';
        solve(curr, n, ans);
        curr.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("", n, ans);
        return ans;
    }
};