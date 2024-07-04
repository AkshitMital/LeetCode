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
// class Solution {
// public:
//     ListNode* mergeNodes(ListNode* head) {
//         head = head->next;
//         ListNode* start = head;
//         while(start){
//             ListNode* end = start;
//             int sum = 0;
//             while(end->val != 0){
//                 sum += end->val;
//                 end = end->next;
//             }
//             start->val = sum;
//             start->next = end->next;
//             start = start->next;
//         }

//         return head;
//     }
// };

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* start = head;
        ListNode* end = head->next;
        int sum = 0;
        while(end){
            if(end->val == 0){
                start = start->next;
                start->val = sum;
                sum = 0;
            }
            else sum += end->val;
            end = end->next;
        }
        start->next = NULL;
        return head->next;
    }
};