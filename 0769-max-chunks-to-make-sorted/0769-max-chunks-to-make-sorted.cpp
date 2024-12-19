class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), maxElement = -1, chunks = 0;
        
        for(int i = 0; i < n; i++){
            maxElement = max(maxElement, arr[i]);

            if(maxElement == i) chunks++;
        }

        return chunks;
    }
};