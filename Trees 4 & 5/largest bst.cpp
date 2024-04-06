//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    vector<int> solve(Node *root, int& ans)
    {
    	if (!root)
    	    return {INT_MAX, INT_MIN, 0};
    	if (!root->left && !root->right)
    	    return {root->data, root->data, 1};

    	vector<int> l = solve(root->left, ans);
    	vector<int> r = solve(root->right, ans);

    	if (l[2] != -1 && r[2] != -1 && l[1] < root->data && root->data < r[0])
    	{
    	    ans = max(ans, 1 + l[2] + r[2]);
    	    return {min(l[0], root->data), max(r[1], root->data), 1 + l[2] + r[2]};
    	}

    // 	ans = max(ans, max(l[2], r[2]));
    	return {root->data, root->data, -1};
    }

    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        /*
        TODO :
        error is ki agr beech me khi me BST bnna bnd hogya
        toh bhi uska count add hoke upr tkk aata jara h,,,,,
        stop this...
        mtlb beech m koi point p break hogya BST 
        aur upr phirse se khi p bnna start hua h 
        tohh phir dono k count alg alg ho and max liya jaye eventually.....
        */
        if (!root) return 0;
    	int ans = 1;
    	solve(root, ans);
    	return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends