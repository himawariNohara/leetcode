class Solution {
public:
    bool canArrange(vector<int>& a, int k) 
    {
        int n = a.size();
        if(n % 2 != 0)
		    return false;   

    	unordered_map<int, int> hash;
	    for(int i = 0; i < n; i++)
		    hash[((a[i] % k) + k) % k]++;

	    for(int i = 0; i < n; i++)
	    {
		    int rem = ((a[i] % k) + k) % k;
            
		    if(rem == 0)
		    {
			    if(hash[rem] % 2 != 0)
				    return false;
		    }
		    else if(2 * rem == k)
		    {
			    if(hash[rem] % 2 != 0)
				    return false;
		    }
		    else
		    {
			    if(hash[rem] != hash[k - rem])
				    return false;
		    }
	    }

	    return true;    
    }
};