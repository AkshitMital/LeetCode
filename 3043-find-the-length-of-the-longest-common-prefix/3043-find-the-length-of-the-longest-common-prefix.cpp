class TrieNode{
private:
    bool isEnd;
    TrieNode* children[26];
    friend class Trie;
};

class Trie{
private:
    TrieNode* root;
    TrieNode* getNode(){
        TrieNode* newNode = new TrieNode();
        newNode->isEnd = false;
        for(int i = 0; i < 26; i++) newNode->children[i] = NULL;
        return newNode;
    }

public:
    Trie(){
        root = getNode();
    }

    void insert(int num){
        TrieNode* crawler = root;
        string n = to_string(num);
        for(int i = 0; i < n.size(); i++){
            int idx = n[i] - '0';
            if(crawler->children[idx] == NULL)
                crawler->children[idx] = getNode();
            crawler = crawler->children[idx];
        }

        crawler->isEnd = true;
    }

    bool search(int num){
        TrieNode* crawler = root;
        string n = to_string(num);
        for(int i = 0; i < n.size(); i++){
            int idx = n[i] - '0';
            if(crawler->children[idx] == NULL)
                return false;
            crawler = crawler->children[idx];
        }

        if(crawler->isEnd == true) return true;

        return false;
    }

    bool startsWith(int num){
        TrieNode* crawler = root;
        string n = to_string(num);
        for(int i = 0; i < n.size(); i++){
            int idx = n[i] - '0';
            if(crawler->children[idx] == NULL)
                return false;
            crawler = crawler->children[idx];
        }

        return true;
    }

    int findLongestPrefix(int num){
        TrieNode* crawler = root;
        string n = to_string(num);
        int common = 0;
        for(int i = 0; i < n.size(); i++){
            int idx = n[i] - '0';
            if(crawler->children[idx] == NULL)
                return common;
            common++;
            crawler = crawler->children[idx];
        }

        return common;
    }

};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        for(int num : arr1) trie.insert(num);

        int longestPrefix = 0;
        for(int num : arr2){
            longestPrefix = max(longestPrefix, trie.findLongestPrefix(num));
        }

        return longestPrefix;
    }
};