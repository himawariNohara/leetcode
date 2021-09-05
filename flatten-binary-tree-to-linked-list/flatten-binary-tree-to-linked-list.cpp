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
    void flatten(TreeNode* root) 
    {
        if(root == NULL)
            return;
        
        stack<struct TreeNode*> s;
        s.push(root);
        
        while(!s.empty())
        {
            struct TreeNode* temp = s.top();
            s.pop();
            
            if(temp->right)
                s.push(temp->right);
            if(temp->left)
                s.push(temp->left);
            
            temp->left = NULL;
            
            if(!s.empty())
                temp->right = s.top();
            else
                temp->right = NULL;
        }
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)
