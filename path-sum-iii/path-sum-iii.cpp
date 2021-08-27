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
    void pathSumUtil(struct TreeNode* root, int targetSum, int& result, unordered_map<int, int>& hash, int presum)
    {
        if(root == NULL)
            return;

        presum += root->val;

        if(presum == targetSum)
            result++;
        
        result += hash[presum - targetSum];
        
        hash[presum]++;

        pathSumUtil(root->left, targetSum, result, hash, presum);
        pathSumUtil(root->right, targetSum, result, hash, presum);

        hash[presum]--;
    }
public:
    int pathSum(TreeNode* root, int targetSum)
    {
        unordered_map<int, int> hash;
        //hash[0] = 1;
        int result = 0;
        pathSumUtil(root, targetSum, result, hash, 0);
        return result;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

