
class Solution
{
public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
        // Your code here
        queue<Node *> q;
        q.push(root);
        int l = 0, e = 0, o = 0;
        while (q.size())
        {
            int s = q.size();
            while (s--)
            {
                Node *t = q.front();
                q.pop();
                if (l % 2 == 0)
                    e += t->data;
                else
                    o += t->data;
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            l++;
        }
        return e - o;
    }
};
