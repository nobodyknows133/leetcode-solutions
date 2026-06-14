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
    int pairSum(ListNode* head) {
        deque<int> q;
        ListNode* tmp = head;
        while(tmp){
            q.push_back(tmp->val);
            tmp = tmp->next;
        }

        int res = 0;
        while(q.size()>0){
            int x = q.back();
            int y = q.front();
            q.pop_back();
            q.pop_front();
            res = max(res, x + y);
        }
        return res;
    }
};
