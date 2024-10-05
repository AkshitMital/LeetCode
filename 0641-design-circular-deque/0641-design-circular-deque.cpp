// class MyCircularDeque {
// private:
//     vector<int> queue;
//     int front;
//     int rear;
//     int size;
//     int cap;
// public:
//     MyCircularDeque(int k) {
//         queue.resize(k);
//         cap = k;
//         front = 0;
//         rear = k-1;
//         size = 0;
//     }
    
//     bool insertFront(int value) {
//         if(isFull()) return false;
//         front = (front - 1 + cap) % cap;
//         queue[front] = value;
//         size++;
//         return true;
//     }
    
//     bool insertLast(int value) {
//         if(isFull()) return false;
//         rear = (rear + 1) % cap;
//         queue[rear] = value;
//         size++;
//         return true;
//     }
    
//     bool deleteFront() {
//         if(isEmpty()) return false;
//         front = (front + 1) % cap;
//         size--;
//         return true;
//     }
    
//     bool deleteLast() {
//         if(isEmpty()) return false;
//         rear = (rear - 1 + cap) % cap;
//         size--;
//         return true;
//     }
    
//     int getFront() {
//         if(isEmpty()) return -1;
//         return queue[front];
//     }
    
//     int getRear() {
//         if(isEmpty()) return -1;
//         return queue[rear];
//     }
    
//     bool isEmpty() {
//         return (size == 0);
//     }
    
//     bool isFull() {
//         return (size == cap);
//     }
// };

class Node{
private:
    int val;
    Node *next, *prev;
    Node(int val){
        this->val = val;
        next = prev = NULL;
    }
    friend class MyCircularDeque;
};

class MyCircularDeque {
private:
    Node *head, *tail;
    int size, cap;
public:
    MyCircularDeque(int k) {
        size = 0;
        cap = k;
        head = tail = NULL;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;

        Node* newNode = new Node(value);

        if(head){
            newNode->next = head;
            head->prev = newNode;
            head = head->prev;
            head->prev = tail;
            tail->next = head;
        }else{
            head = tail = newNode;
            head->prev = tail;
            tail->next = head;
        }

        size++;

        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;

        Node* newNode = new Node(value);
        
        if(tail){
            newNode->prev = tail;
            tail->next = newNode;
            tail = tail->next;
            head->prev = tail;
            tail->next = head;
        }else{
            head = tail = newNode;
            head->prev = tail;
            tail->next = head;
        }

        size++;

        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;

        Node* temp = head;

        if(head != tail){
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }else{
            head = tail = NULL;
        }

        delete temp;

        size--;

        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;

        Node* temp = tail;

        if(head != tail){
            tail = tail->prev;
            head->prev = tail;
            tail->next = head;
        }else{
            head = tail = NULL;
        }

        delete temp;

        size--;

        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return head->val;
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return (size == 0);
    }
    
    bool isFull() {
        return (size == cap);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */