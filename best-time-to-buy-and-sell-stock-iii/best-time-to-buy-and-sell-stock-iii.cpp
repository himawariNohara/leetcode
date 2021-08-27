class Solution {
public:
    int maxProfit(vector<int>& a) 
    {
        int oneBuy = INT_MAX, twoBuy = INT_MAX;
        int oneBuyOneSell = INT_MIN, twoBuytwoSell = INT_MIN;
        
        for(int i = 0; i < a.size(); i++)
        {
            oneBuy = min(oneBuy, a[i]);
            oneBuyOneSell = max(oneBuyOneSell, a[i] - oneBuy);
            twoBuy = min(twoBuy, a[i] - oneBuyOneSell);
            twoBuytwoSell = max(twoBuytwoSell, a[i] - twoBuy);
        }
        
        return twoBuytwoSell;
    }
};