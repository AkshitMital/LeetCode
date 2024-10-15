class TrieNode{
    TrieNode* children[2];
    friend class Trie;
};

class Trie{
private:
    TrieNode* root;
    TrieNode* getNode(){
        TrieNode* newNode = new TrieNode();
        for(int i = 0; i < 2; i++) newNode->children[i] = NULL;
        return newNode;
    }

public:
    Trie(){
        root = getNode();
    }

    void insert(int num){
        TrieNode* crawler = root;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(crawler->children[bit] == NULL) 
                crawler->children[bit] = getNode();
            
            crawler = crawler->children[bit];
        }
    }

    int getMaxXOR(int num){
        TrieNode* crawler = root;
        int maxNum = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;

            if(crawler->children[1-bit] != NULL){
                maxNum = maxNum | (1 << i);
                crawler = crawler->children[1-bit];
            } 
            else crawler = crawler->children[bit];
        }

        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int ans = 0;

        for(int num : nums) trie.insert(num);

        for(int num : nums) ans = max(ans, trie.getMaxXOR(num));

        return ans;
    }
};