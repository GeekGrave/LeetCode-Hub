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
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a;
        a = headA;
        int cnt1=0,cnt2=0;
        while(a!=NULL){
            a=a->next;
            cnt1++;
        }
        a = headB;
        while(a!=NULL){
            a=a->next;
            cnt2++;
        }
        // if(cnt1==cnt2) return headA;
        if(cnt1>cnt2){
            cnt1 = cnt1-cnt2;
            while(cnt1--){
                headA=headA->next;
            }
            while(headA!=headB and headA!=NULL and headB!=NULL){
                headA=headA->next;
                headB=headB->next;
            }
        }
        else{
            cnt2-=cnt1;
            while(cnt2--){
                headB=headB->next;
            }
            while(headA!=headB and headA!=NULL and headB!=NULL){
                headA=headA->next;
                headB=headB->next;
            }
        }
        // cout<<headA->val<<" "<<headB->val;
        return headA;
    }
};