class Solution {
private:
    bool isVowel(char &ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.length();

        unordered_map<char,int> mpp;
        vector<int> nextCons(n, 0);
        int lastConsIdx = n;
        for(int i = n - 1; i >= 0; i--) {
            nextCons[i] = lastConsIdx;
            if(!isVowel(word[i])) lastConsIdx = i;
        }

        int i = 0, j = 0, cons = 0;
        long long count = 0;

        while(j < n) {
            char ch = word[j];
            if(isVowel(ch)) mpp[ch]++;
            else cons++;

            while(cons > k) {
                char ch = word[i];
                if(isVowel(ch)) {
                    mpp[ch]--;
                    if(mpp[ch] == 0) {
                        mpp.erase(ch);
                    }
                } else {
                    cons--;
                }

                i++;
            }

            while(i < n && mpp.size() == 5 && cons == k) {
                count += nextCons[j] - j;

                char ch = word[i];
                if(isVowel(ch)) {
                    mpp[ch]--;
                    if(mpp[ch] == 0) {
                        mpp.erase(ch);
                    }
                } else {
                    cons--;
                }
                i++;
            }

            j++;
        }

        return count;
    }
};