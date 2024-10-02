class TrieNode{
private:
    int prefix;
    TrieNode* children[26];
    friend class Trie;
};

class Trie{
private:
    TrieNode* root;
    TrieNode* getNode(){
        TrieNode* newNode = new TrieNode();
        newNode->prefix = 0;
        for(int i = 0; i < 26; i++) newNode->children[i] = NULL;
        return newNode;
    }
public:
    Trie() { root = getNode(); }

    void insert(string str){
        TrieNode* crawler = root;
        for(int i = 0; i < str.size(); i++){
            int idx = str[i] - 'a';

            if(crawler->children[idx] == nullptr)
                crawler->children[idx] = getNode();

            crawler->children[idx]->prefix += 1;

            crawler = crawler->children[idx];
        }
    }

    int getTotalPrefix(string str){
        TrieNode* crawler = root;
        int total = 0;
        for(int i = 0; i < str.size(); i++){
            int idx = str[i] - 'a';

            total += crawler->children[idx]->prefix;

            crawler = crawler->children[idx];
        }

        return total;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        vector<int> ans;

        for(string& word : words){
            trie.insert(word);
        }

        for(string& word : words){
            int totalPrefix = trie.getTotalPrefix(word);
            ans.push_back(totalPrefix);
        }

        return ans;
    }
};