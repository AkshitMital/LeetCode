// class Node{
// private:
//     pair<int,int> val;
//     Node* next;
//     friend class MinStack;
// public:
//     Node(pair<int,int> val){
//         this->val = val;
//         next = NULL;
//     }
// };

// class MinStack {
// Node* front;
// int mini;
// public:
//     MinStack() {
//         front = NULL;
//         mini = INT_MAX;
//     }
    
//     void push(int val) {
//         mini = min(val, mini);
//         Node* newNode = new Node({val, mini});
//         newNode->next = front;
//         front = newNode;
//         return;
//     }
    
//     void pop() {
//         if (front == NULL) return;

//         Node* temp = front;
//         front = front->next;
//         delete temp;

//         if (front == NULL) {
//             mini = INT_MAX;
//         } else {
//             mini = front->val.second;
//         }
//     }
    
//     int top() {
//         return front->val.first;
//     }
    
//     int getMin() {
//         return front->val.second;
//     }
// };

class MinStack {
private:
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            mini = val;
            st.push(val);
        }else{
            if(mini < val) st.push(val);
            else{
                st.push(val - mini + val);
                mini = val;
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;

        long long topVal = st.top();
        st.pop();

        if (topVal < mini) {
            mini = (2 * mini) - topVal;
        }
    }
    
    int top() {
        if(st.empty()) return INT_MAX;
        long long topVal = st.top();
        if(topVal > mini){
            return topVal;
        }
        return mini;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */