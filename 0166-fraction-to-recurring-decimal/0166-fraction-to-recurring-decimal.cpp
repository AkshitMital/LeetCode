class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";

        string ans = "";
        if(numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0) ans += "-";

        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);

        long long rem = num % den;
        ans += to_string(num / den);

        if(rem == 0) return ans;

        ans += ".";
        unordered_map<long long, int> mpp;
        while(rem != 0){
            if(mpp.find(rem) != mpp.end()){
                int idx = mpp[rem];
                ans.insert(idx, "(");
                ans.push_back(')');
                break;
            }
            mpp[rem] = ans.length();
            rem *= 10;
            ans += to_string(rem / den);
            rem = rem % den;
        }

        return ans;
    }
};