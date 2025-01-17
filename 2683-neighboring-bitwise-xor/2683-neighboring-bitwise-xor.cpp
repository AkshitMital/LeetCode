class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XOR = 0;
        for(int& element : derived) XOR ^= element;

        return (XOR == 0);
    }
};