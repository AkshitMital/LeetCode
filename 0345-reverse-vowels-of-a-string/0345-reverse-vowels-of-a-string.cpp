class Solution {
private:
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
    }
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            while(left < right && !isVowel(s[left])){
                left++;
            }
            while(left < right && !isVowel(s[right])){
                right--;
            }
            if(left < right) swap(s[left++], s[right--]);
        }
        return s;
    }
};