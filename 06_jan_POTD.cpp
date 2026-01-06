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
    int maxLevelSum(TreeNode* root) {
        // Declare Variables
        int maxSum = INT_MIN;
        int resultLevel = 0;
        int currLevel = 1;

        queue<TreeNode*> q;
        q.push(root);

        // traverse intial level
        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            //include the childs and also calculate sum
            while(n--){
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if(node -> left){
                    q.push(node->left);
                }
                if(node -> right){
                    q.push(node->right);
                }
            }

            if(sum > maxSum){
                maxSum = sum;
                resultLevel = currLevel;
            }
            currLevel++;
        }
        //return index
        return resultLevel;
    }
};

// 989
// null 10250
//     98693 -89388
//                -32127
