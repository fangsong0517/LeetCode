/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
struct ListNode *p = head, *q = head;
 if(p == NULL) return false;//如果为空的就返回false;
 do {
     p = p->next;
     q = q->next;
     if(q == NULL || q->next == NULL) return false;
     q = q->next;
 } while(p != q);
    return true;
}
