class Solution {
public:
    int findMin(vector<int>& a) 
    {
        int low = 0, high = a.size() - 1;
        while(low <= high)
        {
            //while(a[low] == a[high] && low != high)
            //    low++;
            
            if(a[low] <= a[high])
                return a[low];
            
            int mid = low + (high - low) / 2;
            
            if(a[low] == a[mid]) //[2,1]
                low++;
            else if(a[low] < a[mid])
                low = mid + 1;
            else
                high = mid;
        }
        return -1;
    }
};

//Time Complexity: O(log n)