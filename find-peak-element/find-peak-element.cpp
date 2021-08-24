class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        int low = 0, high = a.size() - 1;
        while(low <= high)
        {
            if(low == high)
                return low;
            else if(high == low + 1)
                return a[low] > a[high] ? low : high;
            else
            {
                int mid = low + (high - low) / 2;
                if(a[mid] > a[mid - 1] && a[mid] > a[mid + 1])
                    return mid;
                else if(a[mid] < a[mid + 1])
                    low = mid + 1;
                else if(a[mid] < a[mid - 1])
                    high = mid - 1;
            }
        }
        
        return -1;    
    }
};