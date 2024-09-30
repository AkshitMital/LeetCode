class CustomStack {
private:
    vector<int> arr;
    int top;
public:
    CustomStack(int maxSize) {
        arr.resize(maxSize);
        top = -1;
    }
    
    void push(int x) {
        if(top == arr.size()-1) return;
        top += 1;
        arr[top] = x;
    }
    
    int pop() {
        if(top == -1) return -1;
        int ans = arr[top];
        top--;
        return ans;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < k; i++){
            if(i > top) break;
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */