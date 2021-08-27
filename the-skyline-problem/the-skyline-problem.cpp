class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        vector<pair<int, int>> points;
        for(int i = 0; i < buildings.size(); i++)
        {
            points.push_back({buildings[i][0], -buildings[i][2]});
            points.push_back({buildings[i][1], buildings[i][2]});
        }
        sort(points.begin(), points.end());
        
        vector<vector<int>> result;
        multiset<int> max_heap = {0};
        int prev_max = 0;
        for(int i = 0; i < points.size(); i++)
        {
            if(points[i].second < 0)
                max_heap.insert(-points[i].second);
            else
                max_heap.erase(max_heap.find(points[i].second));
            
            int curr_max = *max_heap.rbegin();
            if(curr_max != prev_max)
            {
                result.push_back({points[i].first, curr_max});
                prev_max = curr_max;
            }
        }
        
        return result;
    }
};