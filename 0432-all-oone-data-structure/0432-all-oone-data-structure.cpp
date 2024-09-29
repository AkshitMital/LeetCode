class Node{
private:
public:
    int count;
    list<string> keys;
    Node *next, *prev;
    Node(int k) : count(k), prev(NULL), next(NULL){};
};

class AllOne {
private:
    unordered_map<string, Node*> mpp;
    Node *head, *tail;

    Node* addNode(Node* prevNode, int count){
        Node* newNode = new Node(count);
        Node* nextNode = prevNode->next;

        prevNode->next = newNode;
        newNode->prev = prevNode;
        if(nextNode){
            newNode->next = nextNode;
            nextNode->prev = newNode;
        }
        if(tail == prevNode){
            tail = newNode;
        }

        return newNode;
    }

    void removeNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        if(prevNode) prevNode->next = nextNode;
        if(nextNode) nextNode->prev = prevNode;
        if(tail == node) tail = prevNode;

        delete node;
    }

public:
    AllOne() {
        head = new Node(0);
        tail = head;
    }
    
    void inc(string key) {
        if(mpp.find(key) == mpp.end()){
            if(head->next == NULL || head->next->count != 1){
                addNode(head, 1);
            }
            head->next->keys.push_front(key);
            mpp[key] = head->next;
        }else{
            Node* currNode = mpp[key];
            int currCount = currNode->count;
            if(currNode->next == NULL || currNode->next->count != currCount + 1){
                addNode(currNode, currCount + 1);
            }
    
            currNode->next->keys.push_front(key);
            mpp[key] = currNode->next;
            currNode->keys.remove(key);

            if(currNode->keys.empty()) removeNode(currNode);
        }
    }
    
    void dec(string key) {
        Node* currNode = mpp[key];
        int currCount = currNode -> count;

        currNode->keys.remove(key);
        if(currCount == 1) mpp.erase(key);
        else{
            Node* prevNode = currNode->prev;
            if(prevNode == head || prevNode->count != currCount - 1){
                addNode(prevNode, currCount-1);
            }

            currNode->prev->keys.push_front(key);
            mpp[key] = currNode->prev;
        }

        if(currNode->keys.empty()) removeNode(currNode);
    }
    
    string getMaxKey() {
        return (tail == head) ? "" : tail->keys.front();
    }
    
    string getMinKey() {
        return (head->next == NULL) ? "" : head->next->keys.front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */