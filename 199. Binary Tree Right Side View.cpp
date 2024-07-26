// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.


// Example 1:
// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]

// Example 2:
// Input: root = [1,null,3]
// Output: [1,3]

// Example 3:
// Input: root = []
// Output: []
 

// Constraints:
// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

//  Soluiton:=>

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
    vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
        if (root == NULL) return ans;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
        int flage = 0;
            int size = q.size();
            while(size-- >0) {
                TreeNode *node = q.front();
                q.pop();

                if(flage == 0) {  
                    ans.push_back(node->val);
                    flage++;
                }
                if (node->right !=NULL) {
                    q.push(node->right);
                }
                if (node->left!=NULL) {
                    q.push(node->left);
                }

            }
        }
        return ans;
    }
};
