class TrieNode{
private:
    bool inEndofWord;
    TrieNode* children[26];
    friend class Trie;
};

class Trie {
private:
    TrieNode* root;

    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();

        newNode->inEndofWord = false;

        for(int i = 0; i < 26; i++) newNode->children[i] = NULL;

        return newNode;
    }

public:
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        TrieNode* crawler = root;

        for(int i = 0; i < word.length(); i++){
            int idx = word[i] - 'a';

            if(crawler->children[idx] == NULL){
                crawler->children[idx] = getNode();
            }

            crawler = crawler->children[idx];
        }

        crawler->inEndofWord = true;
    }
    
    bool search(string word) {
        TrieNode* crawler = root;

        for(int i = 0; i < word.length(); i++){
            int idx = word[i] - 'a';

            if(crawler->children[idx] == NULL){
                return false;
            }

            crawler = crawler->children[idx];
        }

        if(crawler->inEndofWord == true) return true;

        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawler = root;

        for(int i = 0; i < prefix.length(); i++){
            int idx = prefix[i] - 'a';

            if(crawler->children[idx] == NULL){
                return false;
            }

            crawler = crawler->children[idx];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */