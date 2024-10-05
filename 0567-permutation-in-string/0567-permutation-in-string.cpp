class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if(n1 > n2) return false;

        unordered_map<char,int> s1mpp;
        unordered_map<char,int> s2mpp;

        for(int i = 0; i < n1; i++){
            s1mpp[s1[i]]++;
            s2mpp[s2[i]]++;
        }

        if(s1mpp == s2mpp) return true;

        for(int i = n1; i < n2; i++){
            s2mpp[s2[i]]++;
            s2mpp[s2[i - n1]]--;
            if(s2mpp[s2[i - n1]] == 0) s2mpp.erase(s2[i - n1]);
            if(s2mpp == s1mpp) return true;
        }

        return false;
    }
};