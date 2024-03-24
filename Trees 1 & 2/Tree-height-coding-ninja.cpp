
int heightOfBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if (!root)
        return 0;
    return 1 + max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right));
}