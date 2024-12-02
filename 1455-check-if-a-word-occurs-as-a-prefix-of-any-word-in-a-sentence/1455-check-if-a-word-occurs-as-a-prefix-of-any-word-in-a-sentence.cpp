class TrieNode{
    int idx = -1;
    TrieNode* children[26];
    friend class Trie;
};

class Trie{
private:
    TrieNode* root;
    TrieNode* getNode(){
        TrieNode* newNode = new TrieNode;
        for(int i = 0; i < 26; i++) newNode->children[i] = NULL;
        return newNode;
    } 
public:
    Trie(){ root = getNode(); }

    void insertWord(string& word, int index){
        TrieNode* crawler = root;
        for(char ch : word){
            if(crawler->children[ch - 'a'] == nullptr){
                crawler->children[ch - 'a'] = getNode();
                crawler->children[ch - 'a']->idx = index;
            }
            crawler = crawler->children[ch - 'a'];
        }
    }

    int startsWith(string& word){
        TrieNode* crawler = root;
        for(char ch : word){
            if(crawler->children[ch - 'a'] == NULL) return -1;
            crawler = crawler->children[ch - 'a'];
        }
        return crawler->idx;
    }
};

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size(), wordIdx = 1;
        Trie trie;
        for(int i = 0; i < n; i++){
            string word = "";
            while(i < n && sentence[i] != ' '){
                word += sentence[i];
                i++;
            }
            // cout << word << endl;
            trie.insertWord(word, wordIdx);
            wordIdx++;
            int ans = trie.startsWith(searchWord);
            if(ans != -1) return ans;
        }
        return -1;
    }
};