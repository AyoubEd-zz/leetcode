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
struct comp{
    bool operator()(const ListNode* p1, const ListNode* p2) {
        return p1->val > p2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        
        for(auto l: lists)
            if(l != nullptr) pq.push(l);
        
        while(!pq.empty()) {
            res->next = pq.top();
            res = res->next;
            if(pq.top()->next != nullptr)
                pq.push(pq.top()->next);
            pq.pop();
        }
        
        return head->next;
    }
};