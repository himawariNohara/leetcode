class Solution {
public:
    int maxCoins(vector<int>& a) 
    {
        a.insert(a.begin(), 1);
        a.push_back(1);
        int n = a.size() - 1;
        
        vector<vector<int>> DP(n + 1, vector<int>(n + 1, 0));
        
        
        
        for(int i = 1; i <= n; i++)
            DP[i][i] = 0;
        
        for(int L = 2; L <= n; L++)
        {
            for(int i = 1; i <= n - L + 1; i++)
            {
                int j = i + L - 1;
                
                DP[i][j] = INT_MIN;
                for(int k = i; k < j; k++)
                {
                    int temp = DP[i][k] + DP[k + 1][j] + a[i -1] * a[k] * a[j];
                    if(temp > DP[i][j])
                        DP[i][j] = temp;
                }
            }
        }
        
        return DP[1][n];
    }
};