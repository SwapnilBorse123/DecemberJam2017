/*
    Date: 12/26/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head){
            return NULL;
        }
        while(head && head->val == val){
            head = head->next;
        }
        ListNode* start = head;
        while(head){
            while(head->next && head->next->val != val){
                head = head->next;
            }
            ListNode* p = head->next;
            //if(p != NULL){
                while(p && p->val == val){
                    p = p->next;
                }
                head->next = p;
                head = head->next;
            //}
        }
        return start;
    }
};