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
    
    TreeNode* newNode(int val)
    {
        TreeNode* temp = new TreeNode;
        temp->val = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    
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
        return result;
    }
    
    void serializeUtil(TreeNode* root, string& result)
    {
        if(root == NULL)
            return;
        
        result += to_string(root->val) + ",";
        serializeUtil(root->left, result);
        serializeUtil(root->right, result);
    }
    
    TreeNode* deserializeUtil(vector<string>& a, int& index, int min, int max)
    {
        if(index == a.size())
            return NULL;
        
        int key = stoi(a[index]);
        
        TreeNode* root = NULL;
        if(key >= min && key <= max)
        {
            root = newNode(key);
            index++;
            root->left = deserializeUtil(a, index, min, key - 1);
            root->right = deserializeUtil(a, index, key + 1, max);
        }
        return root;
    }

    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        string result = "";
        serializeUtil(root, result);
        cout << result << endl;
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        vector<string> a = split(data, ',');
        if(a.size() == 0 || a[0] == "null")
            return NULL;
        
        for(int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout << endl;
        
        int index = 0;
        return deserializeUtil(a, index, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;