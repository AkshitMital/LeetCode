class Solution {
private:
    vector<int> solve(string s){
        vector<int> res;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '+' || s[i] == '-' || s[i] == '*'){
                vector<int> left = solve(s.substr(0, i));
                vector<int> right = solve(s.substr(i+1));

                for(int& x : left){
                    for(int& y : right){
                        if(s[i] == '+') res.push_back(x + y);
                        else if(s[i] == '-') res.push_back(x - y);
                        else if(s[i] == '*') res.push_back(x * y);
                    }
                }
            }
        }

        if(res.empty()) res.push_back(stoi(s));

        return res;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};