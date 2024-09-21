class Solution {
private:
    void solve(int currNum, int n, vector<int>& res){
        if(currNum > n) return;

        res.push_back(currNum);

        for(int append = 0; append <= 9; append++){
            int newNum = currNum*10 + append;

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