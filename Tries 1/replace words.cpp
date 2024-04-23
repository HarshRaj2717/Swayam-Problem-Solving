class Solution {
    struct TrieNode {
        vector<TrieNode*> next;
        bool ended;
        TrieNode() : next(vector<TrieNode*>(26, NULL)), ended(false) {}
    }* root;

    void inserter(string& word) {
        TrieNode* ptr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!ptr->next[word[i] - 'a']) {
                ptr->next[word[i] - 'a'] = new TrieNode();
            }
            ptr = ptr->next[word[i] - 'a'];
        }
        ptr->ended = true;
    }

    string getRoot(string& word) {
        string ans = "";
        TrieNode* ptr = root;
        for (int i = 0; i < word.size() && ptr->next[word[i] - 'a']; i++) {
            ptr = ptr->next[word[i] - 'a'];
            ans.push_back(word[i]);
            if (ptr->ended) {
                return ans;
            }
        }
        return "";
    }

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TrieNode();
        string ans = "";

        for (int i = 0; i < dictionary.size(); i++)
        {
            inserter(dictionary[i]);
        }

        int i = 0;
        while (i < sentence.size()) {
            string word = "";
            while (i < sentence.size() && sentence[i] != ' ') {
                word.push_back(sentence[i]);
                i++;
            }
            i++;
            string r = getRoot(word);
            if (r == "") {
                ans += word;
                ans.push_back(' ');
            } else {
                ans += r;
                ans.push_back(' ');
            }
        }
        if (ans.size() > 0)
            ans.pop_back();
        return ans;
    }
};