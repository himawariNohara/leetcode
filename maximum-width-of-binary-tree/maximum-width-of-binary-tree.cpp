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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        
        queue<pair<struct TreeNode*, long>> q;
        q.push({root, 0});
        int maxWidth = 0;
        
        while(1)
        {
            int n = q.size();
            
            if(n == 0)
                break;
            
            maxWidth = max(maxWidth, (int) (q.back().second - q.front().second + 1));
            
            for(int i = 1; i <= n; i++)
            {
                pair<struct TreeNode*, int> temp_pair = q.front();
                q.pop();
            
                struct TreeNode* temp = temp_pair.first;
                long index = temp_pair.second;
                
                if(temp->left)
                    q.push({temp->left, 2*index + 1});
                if(temp->right)
                    q.push({temp->right, 2*index + 2});
            }
        }
        
        return maxWidth;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)