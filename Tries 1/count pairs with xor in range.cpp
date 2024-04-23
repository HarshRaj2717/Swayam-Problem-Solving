class Solution {
    struct TrieNode {
        int count;
        vector<TrieNode*> next;
        TrieNode() : count(0), next(vector<TrieNode*>(2, NULL)) {}
    }* root;
    void inserter(int num) {
        TrieNode* ptr = root;
        for (int i = 16; i >= 0; i--) {
            int cur = (num & (1 << i)) != 0;
            if (!ptr->next[cur]) {
                ptr->next[cur] = new TrieNode();
            }
            ptr = ptr->next[cur];
            ptr->count += 1;
        }
    }
    int countLesser(int k, int x) {
        TrieNode* ptr = root;
        int ans = 0;
        for (int i = 16; i >= 0 && ptr; i--) {
            int cur_k = (k & (1 << i)) != 0;
            int cur_x = (x & (1 << i)) != 0;

            if (cur_k == 0) {
                ptr = ptr->next[cur_x];
                continue;
            }

            if (ptr->next[cur_x])
                ans += ptr->next[cur_x]->count;

            ptr = ptr->next[!cur_x];
        }
        return ans;
    }

public:
    int countPairs(vector<int>& nums, int low, int high) {
        root = new TrieNode();
        int ans = 0;
        for (int num: nums)
        {
            ans += countLesser(high + 1, num) - countLesser(low, num);
            inserter(num);
        }
        return ans;
    }
};