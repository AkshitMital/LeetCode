class BrowserHistory {
    stack<string> present;
    stack<string> past;
    string curr;
public:
    BrowserHistory(string homepage) {
        curr = homepage;
    }
    
    void visit(string url) {
        present.push(curr);
        past = stack<string>();
        curr = url;
    }
    
    string back(int steps) {
        while(steps != 0 && !present.empty()){
            past.push(curr);
            curr = present.top();
            present.pop();
            steps--;
        }
        return curr;
    }
    
    string forward(int steps) {
        while(steps != 0 && !past.empty()){
            present.push(curr);
            curr = past.top();
            past.pop();
            steps--;
        }
        return curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */