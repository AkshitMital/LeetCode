// class CustomStack {
// private:
//     vector<int> arr;
//     int top;
// public:
//     CustomStack(int maxSize) {
//         arr.resize(maxSize);
//         top = -1;
//     }
    
//     void push(int x) {
//         if(top == arr.size()-1) return;
//         top += 1;
//         arr[top] = x;
//     }
    
//     int pop() {
//         if(top == -1) return -1;
//         int ans = arr[top];
//         top--;
//         return ans;
//     }
    
//     void increment(int k, int val) {
//         for(int i = 0; i < min(k,top+1); i++){
//             arr[i] += val;
//         }
//     }
// };

class CustomStack {
private:
    vector<int> arr;
    vector<int> increments;
    int top, n;
public:
    CustomStack(int maxSize) {
        n = maxSize;
        arr.resize(maxSize);
        increments.resize(maxSize);
        top = -1;
    }
    
    void push(int x) {
        if(top == n-1) return;
        top += 1;
        arr[top] = x;
    }
    
    int pop() {
        if(top == -1) return -1;
        int ans = arr[top] + increments[top];
        if(top-1 >= 0) increments[top-1] += increments[top];
        increments[top] = 0;
        top--;
        return ans;
    }
    
    void increment(int k, int val) {
        int idx = min(k-1, top);
        if(idx >= 0) increments[idx] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */