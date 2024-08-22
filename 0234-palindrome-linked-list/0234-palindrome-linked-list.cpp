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
private:
    ListNode* reverse(ListNode* temp){
        if(temp == NULL || temp->next == NULL) return temp;
        ListNode* last = NULL;
        ListNode* curr = temp;

        while(curr){
            ListNode* nxt = curr->next;
            curr->next = last;
            last = curr;
            curr = nxt;
        }

        return last;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverse(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;

        while(second){
            if(first->val != second->val){
                ListNode* ogHead = reverse(slow->next);
                return false;
            }
            first = first->next;
            second = second->next;
        }

        ListNode* ogHead = reverse(slow->next);

        return true;
    }
};