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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for(int& num : nums) st.insert(num);
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* temp = dummy;
        while(temp->next){
            if(st.find(temp->next->val) != st.end()){
                ListNode* del = temp->next;
                temp->next = temp->next->next;
                delete(del);
            }
            else temp = temp->next;
        }

        return dummy->next;
    }
};