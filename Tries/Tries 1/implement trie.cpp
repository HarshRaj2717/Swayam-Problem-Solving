struct TrieNode {
    char val;
    vector<TrieNode *> next;
    bool isEnd;
    TrieNode(char val): val(val), next(vector<TrieNode *> (26, NULL)), isEnd(false) {}
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode(' ');
    }
    
    void insert(string word) {
        int i = 0;
        TrieNode* ptr = root;
        while (i < word.size() && ptr->next[word[i] - 'a']) {
            ptr = ptr->next[word[i] - 'a'];
            i++;
        }
        for (; i < word.size(); i++) {
            ptr->next[word[i] - 'a'] = new TrieNode(word[i] - 'a');
            ptr = ptr->next[word[i] - 'a'];
        }
        ptr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* ptr = root;
        int i = 0;
        while (i < word.size() && ptr->next[word[i] - 'a']) {
            ptr = ptr->next[word[i] - 'a'];
            i++;
        }
        return i == word.size() && ptr->isEnd == true;
    }
    
    bool startsWith(string word) {
        TrieNode* ptr = root;
        int i = 0;
        while (i < word.size() && ptr->next[word[i] - 'a']) {
            ptr = ptr->next[word[i] - 'a'];
            i++;
        }
        return i == word.size();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */