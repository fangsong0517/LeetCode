/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *ret, *p, *q; // ret是虚拟头结点
    ret.next = head;
    p = &ret;
    q = head;
    while(q&&q->next) {
        p->next = q->next;
        q->next = p->next->next;
        p->next->next = q;
        p = q;
        q = q ->next;
    }
    return ret.next; //返回头结点
}
