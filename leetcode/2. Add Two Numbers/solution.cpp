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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = NULL, *now = NULL;
        int comp = 0;
        for(; l1 != NULL && l2 != NULL ; l1 = l1->next, l2 = l2->next){
            if(ret == NULL){
                ret = new ListNode(l1->val + l2->val + comp);
                now = ret;
            }else{
                now->next = new ListNode(l1->val + l2->val + comp);
                now = now->next;
            }
            printf("%d", now->val);
            if(now->val >= 10){
                comp = 1;
                now->val = now->val % 10;
            }
            else
                comp = 0;
                
        }
        
        for(ListNode* node = l1 != NULL ? l1 : l2 ; node != NULL ; node = node->next){
            now->next = new ListNode(node->val + comp);
            now = now->next;
            
            if(now->val >= 10){
                comp = 1;
                now->val = now->val % 10;
            }
            else
                comp = 0;
        }
        
        if(comp == 1){
            now->next = new ListNode(1);
        }
        return ret;
    }
    
    
};
