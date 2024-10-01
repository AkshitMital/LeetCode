class Solution {
private:
    void solve(int currNum, int& n, vector<int>& res){
        if(currNum > n) return;

        res.push_back(currNum);

        for(int add = 0; add <= 9; add++){
            int newNum = currNum * 10 + add;

            if(newNum > n) return;

            solve(newNum, n, res);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;

        for(int i = 1; i <= 9; i++){
            solve(i, n, res);
        }

        return res;
    }
};