class Solution {
    
    struct compare
    {
        bool operator() (pair<int, int> a, pair<int, int> b)
        {
            return a.second < b.second;
        }
    };
    
public:
    string reorganizeString(string str) 
    {
        vector<int> count(26, 0);
        for(int i = 0; i < str.size(); i++)
            count[str[i] - 'a']++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> max_heap;
        string result = "";
        
        for(int i = 0; i < 26; i++)
        {
            if(count[i] != 0)
                max_heap.push({i, count[i]});
        }
        
        while(max_heap.size() > 1)
        {
            pair<int, int> temp = max_heap.top();
            max_heap.pop();
            int first_highest_char = temp.first;
            int first_highest_count = temp.second;
            result += (first_highest_char + 'a');
            first_highest_count--;
            
            
            temp = max_heap.top();
            max_heap.pop();
            int sec_highest_char = temp.first;
            int sec_highest_count = temp.second;
            result += (sec_highest_char + 'a');
            sec_highest_count--;    
            
            if(first_highest_count != 0) 
                max_heap.push({first_highest_char, first_highest_count});
            
            if(sec_highest_count != 0)
                max_heap.push({sec_highest_char, sec_highest_count});
        }
            
        if(!max_heap.empty())
        {
            if(max_heap.top().second == 1)
                result += (max_heap.top().first + 'a');
            else
                return "";
        }
        
        return result;
    }
};