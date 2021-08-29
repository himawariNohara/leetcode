class Solution {
    
    int largestRectangle(vector<int>& a)
    {
        stack<int> s;
        int area, maxArea = INT_MIN;
        
        int i = 0;
        while(i < a.size())
        {
            if(s.empty() || a[i] > a[s.top()])
            {
                s.push(i);
                i++;
            }
            else
            {
                int tp = s.top();
                s.pop();
                
                area = a[tp] * (s.empty() ? i : i - s.top() - 1);
                
                maxArea = max(maxArea, area);
            }
        }
        
        while(!s.empty())
        {
            int tp = s.top();
            s.pop();
                
            area = a[tp] * (s.empty() ? i : i - s.top() - 1);
                
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& M) 
    {
        int m = M.size();
        
        if(m == 0)
            return 0;
        
        int n = M[0].size();
        
        int maxArea = INT_MIN;
        
        vector<int> a(n, 0);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(M[i][j] == '1')
                    a[j]++;
                else
                    a[j] = 0;
            }
            
            maxArea = max(maxArea, largestRectangle(a));
        }
        
        return maxArea;
    }
};