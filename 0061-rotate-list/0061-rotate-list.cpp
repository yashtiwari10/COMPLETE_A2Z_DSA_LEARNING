class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // Empty list or single node
        if(head == NULL || head->next == NULL)
            return head;

        // Find length and tail
        ListNode* tail = head;
        int length = 1;

        while(tail->next != NULL){
            tail = tail->next;
            length++;
        }

        // Reduce unnecessary rotations
        k = k % length;

        if(k == 0)
            return head;

        // Make the list circular
        tail->next = head;
        // Find the new tail
        int cnt = length - k;
        ListNode* temp = head;

        while(cnt > 1){
            temp = temp->next;
            cnt--;
        }
        // New head
        head = temp->next;
        // Break the circle
        temp->next = NULL;
        return head;
    }
};