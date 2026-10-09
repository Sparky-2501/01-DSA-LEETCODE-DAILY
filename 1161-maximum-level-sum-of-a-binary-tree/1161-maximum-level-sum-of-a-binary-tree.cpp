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
        //queue for BFS , calculate sum at each lev , if(curr>maxSum) maxSum = curr
        //loop till empty queue
        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int ansLevel = 1;
        long long maxSum = LLONG_MIN;

        while (!q.empty()) {
            int size = q.size();
            long long sum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
            }
            if (sum > maxSum) {
                maxSum = sum;
                ansLevel = level;
            }
            level++;
        }
        return ansLevel;
    }
};