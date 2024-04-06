/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void getViews(TreeNode<int> *root, vector<int>& lbv, vector<int>& rv, bool getL = true, bool getR = false, int level = 0)
{
    if (!root)
    {
        return;
    }
    if (getL || (!root->left && !root->right))
        lbv.push_back(root->data);
    else if(getR)
        rv.push_back(root->data);

    level++;
    getViews(root->left, lbv, rv, getL || level == 1, getR && !root->right && level != 1, level);
    getViews(root->right, lbv, rv, getL && !root->left && level != 1, getR || level == 1, level);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> lbv;
    vector<int> rv;

    getViews(root, lbv, rv);

    for (int i = rv.size() - 1; i >= 0; i--)
        lbv.push_back(rv[i]);
    return lbv;
}
