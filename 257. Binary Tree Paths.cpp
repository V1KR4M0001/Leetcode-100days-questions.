// Given the root of a binary tree, return all root-to-leaf paths in any order.
// A leaf is a node with no children.


// Example 1:
// Input: root = [1,2,3,null,5]
// Output: ["1->2->5","1->3"]

// Example 2:
// Input: root = [1]
// Output: ["1"]
 

// Constraints:
// The number of nodes in the tree is in the range [1, 100].
// -100 <= Node.val <= 100

//  Solution:=>

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
public:
    vector<string> ans;
    void solve(TreeNode* root, string s){
        if(!root){
            return ;
        }
        if( root->left == NULL && root->right == NULL){
            s += to_string(root->val);
            ans.push_back(s);
            return ;
        }
        s += to_string(root->val);// Node is stored to string
        s += "->";
        solve(root->left, s);
        solve(root->right, s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        ans.clear();
        string s="";
        solve(root, s);
        return ans;
    }
};
