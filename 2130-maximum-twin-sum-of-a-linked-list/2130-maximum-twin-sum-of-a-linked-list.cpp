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
        // approach:  Finding the middle then flipping the next half and finding
        // the max sum

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast !=NULL && fast->next !=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 1 ptr to end head to first
        int ans = 0;
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            ans = max(ans, first->val + second->val);
            first = first->next;
            second = second->next;
        }
        return ans;
    }
};