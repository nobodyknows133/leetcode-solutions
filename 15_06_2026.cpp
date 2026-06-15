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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return nullptr;
        }
        map<int,ListNode*> mp;
        ListNode* tmp = head;
        int ind = 0;
        while(tmp!=NULL){
            mp[ind++]=tmp;
            tmp=tmp->next;
        }

        int mid = ind/2;
        mp[mid-1]->next = mp[mid+1];
        return head;
    }
};
