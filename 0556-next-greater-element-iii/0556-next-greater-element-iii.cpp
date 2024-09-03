class Solution {
public:
    int nextGreaterElement(int num) {
        string ogNum = to_string(num);
        int n = ogNum.length();

        int i = n-2;
        while(i >= 0 && ogNum[i] >= ogNum[i+1]) i--;
        if(i == -1) return -1;

        int k = n-1;
        while(k > i && ogNum[i] >= ogNum[k]) k--;
        swap(ogNum[i], ogNum[k]);

        sort(ogNum.begin() + i + 1, ogNum.end());

        long long nextNum = stoll(ogNum);
        if(nextNum > INT_MAX) return -1;

        return int(nextNum);
    }
};