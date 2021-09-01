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
    
    void sumEvenGrandparentUtil(TreeNode* current, TreeNode* parent, TreeNode* grandparent, int& sum)
    {
        if(current == NULL)
            return;
        
        if(grandparent != NULL && grandparent->val % 2 == 0)
            sum += current->val;
        
        sumEvenGrandparentUtil(current->left, current, parent, sum);
        sumEvenGrandparentUtil(current->right, current, parent, sum);
    }
    
public:
    int sumEvenGrandparent(TreeNode* root) 
    {
        int sum = 0;
        sumEvenGrandparentUtil(root, NULL, NULL, sum);
        return sum;
    }
};