class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> integers;
        for(int& num : nums) integers.push_back(to_string(num));

        auto lambda = [](string& s1, string& s2){
            if(s1 + s2 > s2 + s1) return true;
            return false;
        };

        sort(integers.begin(), integers.end(), lambda);

        if(integers[0] == "0") return "0";

        string res = "";
        for(string& str : integers) res += str;

        return res;
    }
};