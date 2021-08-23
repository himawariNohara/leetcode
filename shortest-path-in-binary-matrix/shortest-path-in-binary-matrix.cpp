class Solution {
    
    int row[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    int col[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    
    bool isSafe(int x, int y, vector<vector<int>>& M, int m, int n) 
    {
        return x >= 0 && x < m && y >= 0 && y < n && M[x][y] == 0;
    }
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& M) 
    {
        int m = M.size();
        int n = M[0].size();
        
        if(M[0][0] == 1)
            return -1;
        
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        M[0][0] = -1;
        
        while(!q.empty())
        {
            pair<pair<int, int>, int> U = q.front();
            q.pop();
            
            int x = U.first.first;
            int y = U.first.second;
            int count = U.second;
            
            if(x == n - 1 && y == n - 1)
                return count;
            
            for(int k = 0; k < 8; k++)
            {
                int next_x = x + row[k];
                int next_y = y + col[k];
                if(isSafe(next_x, next_y, M, m, n))
                {
                    q.push({{next_x, next_y}, count + 1});
                    M[next_x][next_y] = -1;
                }
            }
        }
        
        return -1;
    }
};