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
    ListNode* oddEvenList(ListNode* head) {
        // o(1) => no extra Node

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even != NULL && even->next != NULL) {
            // Connecting current odd node to next odd node
            odd->next = even->next;
            odd = odd->next;
            // Connecting current even node to next even node
            even->next = odd->next;
            even = even->next;
        }

        // Connecting even list after odd list
        odd->next = evenHead;
        return head;
    }
};