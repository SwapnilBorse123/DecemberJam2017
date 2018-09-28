#include <bits/stdc++.h>

using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public: 
	// ITERATIVE APPROACH
	ListNode* reverseListIterative(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode* p = head;
        if(p->next == NULL){
            return p;
        }
        ListNode* q = p -> next;
        ListNode* r = q -> next;
        head -> next = NULL;
        while(r != NULL){
            q->next = p;
            p = q;
            q = r;
            r = r->next;
        }
        q->next = p;
        return q;
    }

	// RECURSIVE APPROACH
    ListNode* reverseList(ListNode* head) {
     	if(head == NULL){
     		return NULL;
     	}
     	if(head->next == NULL){
     		return head;
     	}
     	if(head->next->next == NULL){
     		ListNode* start = head->next;
     		start->next = head;
     		start->next->next = NULL;
     		return start;
     	}
     	ListNode* start = NULL;
     	recReverse(start, head, head->next);
     	return start;
    }

    void recReverse(ListNode* start, ListNode* head, ListNode* tail){
    	if(tail -> next == NULL){
    		start = tail;
            cout << "assigning start to: " << tail->val << "\n";
            tail->next = head;
            cout << "making " << tail->val << " 's next: " << head->val << "\n";
    		return;
    	}else{
    		recReverse(start, head->next, tail->next);
    		tail->next = head;
            cout << "making " << tail->val << " 's next: " << head->val << "\n";
    		head->next = NULL;
            cout << "making " << head->val << " 's next: " << "NULL" << "\n";
    	}
    }
};

int main(){
	Solution s;
	//cout << s.
	return 0;
}