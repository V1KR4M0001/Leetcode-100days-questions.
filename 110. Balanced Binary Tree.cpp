// Given a binary tree, determine if it is height-balanced.


// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: true

// Example 2:
// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false

// Example 3:
// Input: root = []
// Output: true
 

// Constraints:
// The number of nodes in the tree is in the range [0, 5000].
// -104 <= Node.val <= 104

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
    int treeHeight(TreeNode* root, int& height) {
        if(root == NULL) return 0;
        int left = treeHeight(root->left, height) +1;
        int right = treeHeight(root->right, height) +1;

        if(abs(right-left)>1) height=0;

        return max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        
        int height = 1;
        treeHeight(root, height);
        if(height) return true;
        else return false;
    }
};

// 2nd and more relevant code :=>

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
    pair<bool, int> solve(TreeNode* root) {
        if(!root) return {true, 0};
        // pair<isBalanced, height>
        pair<bool, int> l=solve(root->left);
        pair<bool, int> r=solve(root->right);
        // calculation at some particular node
        pair<bool, int> ans;
        int height=max(l.second, r.second)+1;
        bool isBalanced;
        if(abs(l.second-r.second)<=1 && l.first==true && r.first==true) {
            isBalanced = true;
        } else {
            isBalanced = false;
        }
        ans.first=isBalanced;
        ans.second=height;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        pair<bool, int> ans=solve(root);
        return ans.first;
    }
};
