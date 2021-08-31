class Solution {
    
    bool DFS(int u, int n, vector<vector<int>>& adj, vector<int>& color)
    {
        //cout << u << endl;
        color[u] = 1;
        
        for(auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            int v = *it;
           // cout << "v" << v << endl;
            if(color[v] == 0)
            {
                if(DFS(v, n, adj, color))
                    return true;
            }
            else if(color[v] == 1)
                return true;
        }
        
        color[u] = 2;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        //stak<int> s;
        vector<bool> visited(numCourses, false);
        vector<int> color(numCourses, 0);
        
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
                
        for(int i = 0; i < numCourses; i++)
        {
            if(color[i] == 0)
            {
                if(DFS(i, numCourses, adj, color))
                    return false;
            }
        }
        
        return true;
    }
};