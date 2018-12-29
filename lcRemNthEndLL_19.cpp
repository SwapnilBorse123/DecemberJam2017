
/*
    Date: 12/28/2018
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return head;
        }
        ListNode dummy(-1); dummy.next = head;
        ListNode* hare = &dummy, *turtle = &dummy;
        //cout << turtle->next->val << endl;
        while(n > 0){
            hare = hare->next;
            n--;
        }
        while(hare->next){
            hare = hare->next;
            turtle = turtle->next;
        }
        if(turtle && turtle->next){
            turtle->next = turtle->next->next;   
        }
        return dummy.next;
    }
};