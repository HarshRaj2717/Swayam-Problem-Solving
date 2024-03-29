class Solution
{
public:
    bool helper(TreeNode *root, int n, string &s)
    {
        if (!root)
            return false;
        else if (root->val == n)
            return true;
        s += "L";
        if (helper(root->left, n, s))
            return true;
        s.pop_back();
        s += "R";
        if (helper(root->right, n, s))
            return true;
        s.pop_back();
        return false;
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        string s, e;
        helper(root, startValue, s);
        helper(root, destValue, e);
        int k = 0;
        string ans;
        while (k < s.size() && k < e.size() && s[k] == e[k])
            k++;
        for (int i = k; i < s.size(); i++)
            ans.push_back('U');
        for (int i = k; i < e.size(); i++)
            ans.push_back(e[i]);
        return ans;
    }
};