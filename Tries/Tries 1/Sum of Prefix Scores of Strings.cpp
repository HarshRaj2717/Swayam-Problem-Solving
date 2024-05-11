class Solution {
    struct TrieNode {
        int count;
        char val;
        vector<TrieNode *> next;
        TrieNode(char val): count(1), val(val), next({}) {}
    }*root;

    TrieNode* finder(vector<TrieNode *> &next, char c)
    {
        for (int i = 0; i < next.size(); i++)
        {
            if (next[i]->val == c)
            {
                return next[i];
            }
        }
        return NULL;
    }

    void inserter(const string &word)
    {
        int i = 0;
        TrieNode *ptr = root;
        TrieNode *temp = finder(root->next, word[i]);
        while (i < word.size() && temp != NULL)
        {
            ptr = temp;
            ptr->count += 1;
            i++;
            temp = finder(ptr->next, word[i]);
        }
        while (i < word.size())
        {
            TrieNode* temp = new TrieNode(word[i]);
            ptr->next.push_back(temp);
            ptr = temp;
            i++;
        }
    }

    int counter(const string &word)
    {
        int ans = 0;
        int i = 0;
        TrieNode *temp = finder(root->next, word[i]);
        TrieNode *ptr = root;
        while (i < word.size() && temp != NULL)
        {
            ptr = temp;
            ans += ptr->count;
            i++;
            temp = finder(ptr->next, word[i]);
        }
        return ans;
    }

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        root = new TrieNode(' ');
        root->count = 0;
        vector<int> ans(words.size(), 0);
        for (int i = 0; i < words.size(); i++)
        {
            inserter(words[i]);
        }
        for (int i = 0; i < words.size(); i++)
        {
            ans[i] = counter(words[i]);
        }
        return ans;
    }
};