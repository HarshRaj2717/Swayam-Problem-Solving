class Solution {
    struct TrieNode {
        int ans;
        int len;
        TrieNode* next[26];
        TrieNode(): ans(-1) {
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
        TrieNode(int ans, int len): ans(ans), len(len) {
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
    }*root;

    void inserter(int index, string& word) {
        TrieNode *ptr = root;
        for (int i = word.size() - 1; i >= 0; i--)
        {
            char c = word[i];
            if (!ptr->next[c - 'a'])
            {
                ptr->next[c - 'a'] = new TrieNode(index, word.size());
            }
            ptr = ptr->next[c - 'a'];
            if (ptr->len > word.size())
            {
                ptr->len = word.size();
                ptr->ans = index;
            }
        }
    }

    int getAns(string& word) {
        TrieNode *ptr = root;
        for (int i = word.size() - 1; i >= 0; i--)
        {
            if (!ptr->next[word[i] - 'a'])
            {
                break;
            }
            ptr = ptr->next[word[i] - 'a'];
        }
        return ptr->ans;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        root = new TrieNode();
        vector<int> ans;
        int min_len_index = 0;
        for (int i = 0; i < wordsContainer.size(); i++)
        {
            inserter(i, wordsContainer[i]);
            if (wordsContainer[i].size() < wordsContainer[min_len_index].size())
            {
                min_len_index = i;
            }
        }
        root->ans = min_len_index;
        for (int i = 0; i < wordsQuery.size(); i++)
        {
            ans.push_back(getAns(wordsQuery[i]));
        }
        return ans;
    }
};