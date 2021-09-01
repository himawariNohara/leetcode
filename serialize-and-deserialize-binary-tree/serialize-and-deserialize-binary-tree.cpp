/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    
    vector<string> split(string str, char delim)
    {
        vector<string> result;
        stringstream s(str);
        
        while(s.good())
        {
            string temp;
            getline(s, temp, delim);
            result.push_back(temp);
        }       
        
        result.pop_back();
        for(int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        
        return result;
    }
    
    TreeNode* newNode(int val)
    {
        TreeNode* temp = new TreeNode;
        temp->val = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string result;
        if(root == NULL)
            return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp == NULL)
                result += "null,";
            else
            {
                result += to_string(temp->val) + ",";
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        
        cout << result << endl;
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        vector<string> a = split(data, ',');
        if(a.size() == 0 || a[0] == "null")
            return NULL;
               
        int i = 0;
        TreeNode* root = newNode(stoi(a[i]));
        i++;
        queue<TreeNode*> q;
        q.push(root);
        
        while(i < a.size())
        {
            TreeNode* parent = q.front();
            q.pop();
            
            TreeNode* left = NULL;
            if(a[i] != "null")
            {
                left = newNode(std::stoi(a[i]));
                q.push(left);
                
            }
            i++;
            parent->left = left;
            
            if(i < a.size())
            {
                TreeNode* right = NULL;
                if(a[i] != "null")
                {
                    right = newNode(stoi(a[i]));
                    q.push(right);
                }
                i++;
                parent->right = right;
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));