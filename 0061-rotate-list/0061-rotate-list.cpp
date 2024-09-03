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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        int size = 1;
        ListNode* temp = head;
        while(temp->next){
            temp = temp->next;
            size++;
        }
        cout << size << endl;

        k %= size;
        cout << k << endl;

        temp->next = head;
        temp = temp->next;

        int left = size - k - 1;
        cout << left;
        while(left > 0 && temp){
            temp = temp->next;
            left--;
        }
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};