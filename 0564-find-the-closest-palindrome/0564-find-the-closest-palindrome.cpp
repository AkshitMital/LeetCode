class Solution {
private:
    long fun(long firstHalf, bool isEven){
        long resultNum = firstHalf;
        if(!isEven) firstHalf /= 10;

        while(firstHalf > 0){
            int digit = firstHalf % 10;
            resultNum = (resultNum * 10) + digit;

            firstHalf /= 10;
        }

        return resultNum;
    }
public:
    string nearestPalindromic(string n) {
        int l = n.length();
        int mid = l/2;

        int firstHalfLength = (l%2 == 0) ? mid : mid + 1;
        long firstHalf = stol(n.substr(0, firstHalfLength));

        vector<long> possibilities;

        possibilities.push_back(fun(firstHalf, (l%2 == 0)));
        possibilities.push_back(fun(firstHalf + 1, (l%2 == 0)));
        possibilities.push_back(fun(firstHalf - 1, (l%2 == 0)));
        possibilities.push_back((long)pow(10, l) + 1);
        possibilities.push_back((long)pow(10, l-1) - 1);

        long res = LONG_MAX;
        long originalNum = stol(n);
        long diff = LONG_MAX;
        for(auto num : possibilities){
            if(num == originalNum) continue;
            if(abs(originalNum - num) < diff){
                res = num;
                diff = abs(originalNum - num);
            }
            else if(abs(originalNum - num) == diff) res = min(res, num);
        }

        return to_string(res);
    }
};