/*
Date: 12/24/2018
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        vector<int> dups;
        ListNode* start = head, *p = head, *q = head;
        while(q){ // get the duplicates
            int count = 0;
            while(q && p && (p->val == q->val)){
                count++;
                q = q->next;
            }
            if(count > 1){
                dups.push_back(p->val);
            }
            p = q;
        }
        while(start && binary_search(dups.begin(), dups.end(), start->val)){
            start = start->next;
        }
        if(!start) {return NULL;}
        head = p = start; // reusing pointer p
        while(p){
            while(p->next && binary_search(dups.begin(), dups.end(), p->next->val)){
                p = p->next;
            }
            start->next = p->next;
            start = start->next;
            p = start;
        }
        // for(auto &it: dups){
        //     cout << it << " ";
        // }
        return head;
    }
};

/*
ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* start = head, *p = head, *q = head;
        while(q){
            int count = 0;
            while(q && p && (p->val == q->val)){
                count++;
                q = q->next;
            }
            if(count > 1){
                start->next = q;
                
            }else{
                if(start->next != q){
                    start->next = q;
                    start = start->next;
                }
                p = q;
            }
        }
        return head;
    }
    */