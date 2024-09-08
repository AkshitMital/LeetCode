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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        ListNode* curr = head;
        while(curr){
            size++;
            curr = curr->next;
        }

        int divElement = size / k;
        int extraElements = size % k;

        curr = head;
        vector<ListNode*> ans;
        while(curr){
            int add = (extraElements > 0) ? divElement : divElement-1;

            ListNode* temp = curr;
            while(add-- && temp->next){
                temp = temp->next;
            }
            ListNode* nxt = temp->next;
            temp->next = NULL;
            ans.push_back(curr);
            curr = nxt;
            extraElements--;
        }

        while(ans.size() < k) ans.push_back({NULL});
        
        return ans;
    }
};