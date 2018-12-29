
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
    vector<ListNode*> res;
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = 0;
        ListNode* start = root;
        while(start){
            len++;
            start = start->next;
        }
        start = root;
        if(k > len){
            ListNode* temp;
            while(k-- > 0){
                res.emplace_back(root);
                if(root){
                    temp = root->next;
                    root->next = NULL;
                    root = temp;
                }
            }
        }else{
            int partLen = len / k, extra = len % k, jumps = 0;
            while(root != NULL){
                res.emplace_back(root);
                //cout << "pushing " << root->val << endl;
                jumps = extra <= 0 ? partLen-1 : partLen;
                //cout<< "jumps: " << jumps << endl;
                while(jumps > 0 && root){
                    root = root->next;
                    //cout << root->val << " ";
                    jumps--;
                }
                //cout << "root after jumps: " << root->val << endl;
                if(root){
                    ListNode* temp = root->next;
                    root->next = NULL;
                    root = temp;
                }
                extra--;
                if(!root) break;
            }
        }
        return res;
    }
};