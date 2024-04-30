/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    ListNode* cur_node;
    TreeNode* solver(int s, int e)
    {
        if (s > e)
            return NULL;
        
        TreeNode* root = new TreeNode;
        int m = s + (e - s) / 2;
        root->left = solver(s, m - 1);
        root->val = cur_node->val;
        cur_node = cur_node->next;
        root->right = solver(m + 1, e);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return NULL;
        cur_node = head;
        ListNode* ptr = head;
        int n = 0;
        while (ptr)
        {
            ptr = ptr->next;
            n++;
        }
        return solver(0, n - 1);
    }
};