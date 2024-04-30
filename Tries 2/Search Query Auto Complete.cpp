/*
NOT EXACT SOLUTION BUT COMPLETELY SAME APPROACH FROM A PREVIOUS QUES WITH MINIMAL CHANGES
*/


#include <bits/stdc++.h>

using namespace std;

struct TrieNode
{
    char val;
    vector<TrieNode *> next;
    bool isEnd;
    TrieNode(char val) : val(val), next(vector<TrieNode *>(26, NULL)), isEnd(false) {}
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode(' ');
    }

    void insert(string word)
    {
        int i = 0;
        TrieNode *ptr = root;
        while (i < word.size() && ptr->next[word[i] - 'a'])
        {
            ptr = ptr->next[word[i] - 'a'];
            i++;
        }
        for (; i < word.size(); i++)
        {
            ptr->next[word[i] - 'a'] = new TrieNode(word[i] - 'a');
            ptr = ptr->next[word[i] - 'a'];
        }
        ptr->isEnd = true;
    }

    void getAllStrings(vector<string> &res, TrieNode *ptr, string &cur)
    {
        if (ptr->isEnd)
        {
            res.push_back(cur);
        }

        for (int i = 0; i < 26; i++)
        {
            if (ptr->next[i])
            {
                cur.push_back('a' + i);
                getAllStrings(res, ptr->next[i], cur);
                cur.pop_back();
            }
        }
    }

    vector<string> autoComplete(string word)
    {
        vector<string> res;
        res.push_back(word);
        TrieNode *ptr = root;
        int i = 0;
        while (i < word.size() && ptr->next[word[i] - 'a'])
        {
            ptr = ptr->next[word[i] - 'a'];
            i++;
        }
        if (i != word.size())
        {
            return res;
        }
        getAllStrings(res, ptr, word);
        return res;
    }
};

int main()
{
    Trie *t = new Trie();
    t->insert("hello");
    t->insert("dog");
    t->insert("hell");
    t->insert("cat");
    t->insert("a");
    t->insert("hel");
    t->insert("help");
    t->insert("helps");
    t->insert("helping");

    vector<string> res = t->autoComplete("hel");
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;

    return 0;
}