class Solution {
    struct TrieNode {
        vector<TrieNode *> next;
        TrieNode(): next(vector<TrieNode *> (2, NULL)) {}
    }*root;
    void inserter(int num)
    {
        TrieNode *ptr = root;
        for (int i = 31; i >= 0; i--)
        {
            int cur = (num & (1 << i)) != 0;
            if (!ptr->next[cur])
            {
                ptr->next[cur] = new TrieNode();
            }
            ptr = ptr->next[cur];
        }
    }
    int findMaxXOR(int num)
    {
        int res = 0;
        TrieNode *ptr = root;
        for (int i = 31; i >= 0 && ptr; i--)
        {
            int cur = (num & (1 << i)) != 0;
            if (ptr->next[!cur])
            {
                ptr = ptr->next[!cur];
                res |= (1 << i);
                continue;
            }
            ptr = ptr->next[cur];
        }
        return res;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        root = new TrieNode();
        for (int num: nums)
        {
            ans = max(ans, findMaxXOR(num));
            inserter(num);
        }
        return ans;
    }
};