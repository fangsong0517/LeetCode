/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p1 = headA, *p2 = headB;
    while(p1!=p2) {
        p1 = (p1 == NULL ? headB : p1->next);
        p2 = (p2 == NULL ? headA : p2->next);
    }
    return p1;
}
