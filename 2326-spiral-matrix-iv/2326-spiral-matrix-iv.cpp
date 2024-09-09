/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n,-1));
        ListNode* curr = head;
        int row = 0, col = 0, top = 0, bottom = m-1, left = 0, right = n-1;
        int dir = 0;
        
        while(left <= right && top <= bottom){
            if(dir == 0){
                for(int i = left; i <= right && head != NULL; i++){
                    matrix[top][i] = head->val;
                    head = head->next;
                }
                top++;
            }

            if(dir == 1){
                for(int i = top; i <= bottom && head != NULL; i++){
                    matrix[i][right] = head->val;
                    head = head->next;
                }
                right--;
            }

            if(dir == 2){
                for(int i = right; i >= left && head != NULL; i--){
                    matrix[bottom][i] = head->val;
                    head = head->next;
                }
                bottom--;
            }

            if(dir == 3){
                for(int i = bottom; i >= top && head != NULL; i--){
                    matrix[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }

            dir = (dir + 1) % 4;
        }

        return matrix;
    }
};