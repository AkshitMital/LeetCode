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
    ListNode* findKthNode(ListNode* curr, int k){
        k -= 1;
        while(curr && k--){
            curr = curr->next;
        }
        return curr;
    }

    ListNode* reverse(ListNode* curr){
        ListNode* last = NULL;
        ListNode* newHead = curr;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = last;
            last = curr;
            curr = nxt;
        }

        return last;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || !head) return head;

        ListNode* temp = head;
        ListNode* nextNode = NULL;
        ListNode* prevNode = NULL;

        while(temp){
            ListNode* kthNode = findKthNode(temp, k);
            if(kthNode == NULL){
                if(prevNode) prevNode->next = temp;
                break;
            }

            nextNode = kthNode->next;
            kthNode->next = NULL;

            ListNode* newHead = reverse(temp);

            if(!prevNode) head = newHead;
            else prevNode->next = newHead;

            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
};