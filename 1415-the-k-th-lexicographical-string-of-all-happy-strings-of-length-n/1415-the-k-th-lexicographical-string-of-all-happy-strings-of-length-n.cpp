class Solution {
private:
    void solve(string& curr, int& k, int n, int& count, string& result) {
        if(curr.length() == n) {
            count++;
            if(count == k) {
                result = curr;
            }

            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++) {
            if(!curr.empty() && curr.back() == ch) continue;
            
            
            curr.push_back(ch);

            solve(curr, k, n, count, result);

            curr.pop_back();
        }
    }
public:
    string getHappyString(int n, int k) {
        string curr = "";
        string result = "";
        int count;

        solve(curr, k, n, count, result);

        return result;
    }
};