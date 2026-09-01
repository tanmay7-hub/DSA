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
    bool isValid(ListNode* last , ListNode*pprev , ListNode* curr){
        return (last->val > pprev->val && last->val > curr->val) || (last->val < pprev->val && last->val < curr->val);
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
       ListNode* pprev = NULL;
       ListNode* last = NULL; 
       ListNode* curr = head;

       int i = 0;
       int prev = -1 ,  first = -1;
       vector<int> ans(2 , INT_MAX);
       while(curr != NULL){
        if(pprev != NULL && last != NULL && isValid(last , pprev , curr)){

            if(first == -1)first = i;

             if(prev != -1){
                ans[0] = min(ans[0] , i - prev  );
                ans[1] = i - first;
               
             }
                prev = i;
             
        }

        pprev= last;
        last = curr;
        curr = curr->next;
        i++;
       }
        
      if(ans[0] == INT_MAX)return {-1 , -1};
       return ans;
    }
};