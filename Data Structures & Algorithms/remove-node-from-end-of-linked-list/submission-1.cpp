class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create dummy node
        ListNode dummy(0);
        dummy.next = head;

        // Initialize pointers
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // Move fast n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both until fast hits NULL
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete the nth node from end
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        // Return the updated list
        return dummy.next;
    }
};
