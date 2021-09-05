class BrowserHistory 
{
    vector<string> history;
    int current;
    
public:
    BrowserHistory(string homepage) 
    {
        history.push_back(homepage);
        current = 0;
    }
    
    void visit(string url) 
    {
        if(current < history.size() - 1)
            history.erase(history.begin() + current + 1, history.end());        
        history.push_back(url);
        current++;
    }
    
    string back(int steps) 
    {
        current = max(0, current - steps);
        return history[current];
    }
    
    string forward(int steps) 
    {
        current = min(current + steps, (int) history.size() - 1);
        return history[current];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */