/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* p, TreeNode* q) {
        // base case if both the values are 1 then return true
        if (p == NULL && q == NULL) {
            return true;
        }

        // if one of them is NULL and the other one is non null
        // then return false
        if (p == NULL || q == NULL) {
            return false;
        }
        return (p->val == q->val) &&  // checking their values
                // checking both the condition when filpped and when non flipped
               (solve(p->left, q->left) || solve(p->left, q->right)) &&  
               (solve(p->right, q->left) || solve(p->right, q->right));
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return solve(root1, root2); //returning answer
    }
};
