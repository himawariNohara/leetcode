class Solution {
public:
    int minSteps(string s, string t) 
    {
        vector<int> count(26, 0);
        for(int i = 0; i < s.size() && i < t.size(); i++)
        {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        
        int result = 0;
        for(int i = 0; i < 26; i++)
        {
            if(count[i] > 0)
                result += count[i];
        }
        
        return result;
    }
};