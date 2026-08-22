class Solution {
public:

    ListNode* reverseLinks(ListNode* groupHead, int k) {
        ListNode* groupEnd = groupHead;

        for (int i = 1; i < k; i++) {
            groupEnd = groupEnd->next;
        }
        ListNode* nextGroup = groupEnd->next;

        ListNode* prev = nextGroup;
        ListNode* curr = groupHead;

        while (curr != nextGroup) {
            ListNode* next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == NULL || k == 1) {
            return head;
        }

        ListNode* temp = head;
        ListNode* prevGroup = NULL;
        ListNode* groupHead = head;

        while (temp != NULL) {

            int cnt = 1;

            while (temp != NULL && cnt < k) {
                temp = temp->next;
                cnt++;
            }

            if (temp == NULL) {
                break;
            }

            ListNode* groupEnd = temp;
            ListNode* nextGroup = groupEnd->next;

            ListNode* revPrevGroup = reverseLinks(groupHead, k);

            if (prevGroup == NULL) {
                head = revPrevGroup;
            }
            else {
                prevGroup->next = revPrevGroup;
            }

            prevGroup = groupHead;

            groupHead = nextGroup;
            temp = nextGroup;
        }
        return head;
    }
};