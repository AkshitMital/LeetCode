class Solution {
public:
    bool isCircularSentence(string sentence) {
        string firstWord, prevWord, currWord;
        stringstream ss(sentence);

        ss >> firstWord;

        prevWord = firstWord;
    
        while (ss >> currWord) {
            if (prevWord.back() != currWord.front())
                return false;
            
            prevWord = currWord;
        }
        
        return prevWord.back() == firstWord.front();
    }
};