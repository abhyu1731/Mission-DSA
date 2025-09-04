
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<int>res;
        ListNode* t=head;
        while(t){
            res.push_back(t->val);
            t=t->next;
        }
        if(res.size()<=1) return head;
        t=head;
        int i=0;
        sort(res.begin(),res.end());
        while(t){
            t->val=res[i];
            i++;t=t->next;
        }
        return head;
    }
};
