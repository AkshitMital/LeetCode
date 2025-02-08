class NumberContainers {
    unordered_map<int, int> index2num;
    unordered_map<int, set<int>> num2index;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(index2num.find(index) != index2num.end()) {
            int prevNum = index2num[index];
            num2index[prevNum].erase(index);
            if(num2index[prevNum].empty()) num2index.erase(prevNum);
        }

        index2num[index] = number;
        num2index[number].insert(index);
    }
    
    int find(int number) {
        return (num2index.count(number)) ? (*num2index[number].begin()) : -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */