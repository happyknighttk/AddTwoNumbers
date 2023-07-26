/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* createNode(int val)
{
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* lsum = NULL;
    struct ListNode* current = NULL;
    int carry = 0;

    while (l1 || l2 || carry)
    {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = sum / 10;
        sum = sum % 10;

        if (!lsum)
        {
            lsum = createNode(sum);
            current = lsum;
        }
        else
        {
            current->next = createNode(sum);
            current = current->next;
        }

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }

    return lsum;
}
