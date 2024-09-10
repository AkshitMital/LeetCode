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
    int findGCD(int a, int b){
        if(a == 0) return b;

        return findGCD(b%a, a);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while(curr->next) {
            ListNode* nxt = curr->next;
            int b = nxt->val;
            int a = curr->val;

            int gcd = findGCD(a, b);
            ListNode* newNode = new ListNode(gcd);
            curr->next = newNode;
            newNode->next = nxt;

            curr = nxt;
        }

        return head;
    }
};