class Node{
private:
    pair<int,int> val;
    Node* next;
    friend class MinStack;
public:
    Node(pair<int,int> val){
        this->val = val;
        next = NULL;
    }
};

class MinStack {
Node* front;
int mini;
public:
    MinStack() {
        front = NULL;
        mini = INT_MAX;
    }
    
    void push(int val) {
        mini = min(val, mini);
        Node* newNode = new Node({val, mini});
        newNode->next = front;
        front = newNode;
        return;
    }
    
    void pop() {
        if (front == NULL) return;

        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == NULL) {
            mini = INT_MAX;
        } else {
            mini = front->val.second;
        }
    }
    
    int top() {
        return front->val.first;
    }
    
    int getMin() {
        return front->val.second;
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